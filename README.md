# myMiniKV

+ git submodule update --init
+ make
+ server: ./kvstore     // port: 9096
+ client: ./test -s 127.0.0.1 -p 9096 -m 1
+ client: go build go-kvstore.go   ./go-kvstore 
