#include <seastar/core/app-template.hh>
#include <seastar/core/coroutine.hh>
#include <seastar/util/log.hh>

namespace {
seastar::logger lg("hello-world");
}

static seastar::future<> hello_from_all_cores() {
    for (unsigned i = 0; i < seastar::smp::count; ++i) {
    co_await seastar::smp::submit_to(i, [] {
        lg.info("App is running on core {}", seastar::this_shard_id());
        });
    }
    co_return;
}

int main(int argc, char** argv) {
    seastar::app_template app;
    return app.run(argc, argv, [&]() -> seastar::future<int> {
        co_await hello_from_all_cores();
        co_return 0;
    });
}