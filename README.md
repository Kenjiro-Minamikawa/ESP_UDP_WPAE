# UDP Library for ESP32
## メンバ関数

### `void Init(const char* id, const char* pwd)`

`id`には自分の学籍番号（ex. e1838）、`pwd`には自分の学校のWiFiのパスワードを入れる。

### `int available()`
データが送信されてきていて、かつそのデータが255(`0xff`)のときに`1`を返す。
それ以外のときは`-1`を返す。

### `double read()`
データを読み取って、doubleで返す。

## Example
```cpp
double a=0;

void setup(){
  Serial.begin(115200);
  udp1.Init("e1838","**pwd**");
}

void loop(){
  if(udp1.available()){
    a = udp1.read();
    Serial.println(a);
  }
}
```