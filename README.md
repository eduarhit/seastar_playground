# seastar_playground

docker build -t seastar-dev -f docker/dev/Dockerfile .

seabuild() { docker run -v $HOME/seastar/:/seastar -u $(id -u):$(id -g) -w /seastar -t seastar-dev "$@"; }

$ seabuild ./configure.py
$ seabuild ninja -C build/release
