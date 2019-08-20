all: clean deps

clean:
    @rm -rf go.mod
    @rm -rf go.sum
    @rm -rf vendor

deps:
    @echo "初始化模块"
    go mod init wages_service
    @echo "下载依赖"
    export GOPROXY=http://goproxy.io
    go mod tidy -v
    @echo "检查依赖是否全部下载"
    go mod verify
    @echo "创建vendor"
    go mod vendor
