# seastar_playground
```
docker build -t seastar-dev -f docker/dev/Dockerfile .

seabuild([main.cc](main.cc)) { docker run -v $PWD:/seastar -u $(id -u):$(id -g) -w /seastar -t seastar-dev "$@"; }

seabuild ./configure.py
seabuild ninja
.seabuild /hello-world
```
