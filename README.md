# seastar_playground

To start using this repo you need to have Docker installed.

Then you can build the Docker image
```
docker build -t seastar-dev -f docker/dev/Dockerfile .
```

For more comfortability, create an alias to call docker run (it will disappear when you close the shell session)
```
seabuild() { docker run -v $PWD:/seastar -u $(id -u):$(id -g) -w /seastar -t seastar-dev "$@"; }
```

Now you can create the ninja project and build it, and run the example
```
seabuild cmake -GNinja
seabuild ninja
seabuild ./hello-world
```

After that you can modify the main.cc file as you wish, then build, run the hello-world again, etc.
```
seabuild ninja
seabuild ./hello-world
```


