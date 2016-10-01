int f[5];

void setup(){
  int i;
  //モニタリングのためシリアル通信開始
  Serial.begin(9600);
  for(i = 0; i < 5; i++) {
    //ピンをデジタル出力
    pinMode(i * 2,OUTPUT);
    //ピンをデジタル入力
    pinMode(i * 2 + 1,INPUT);    
  }
}

void loop(){
  int n = 4;
  char data;
  if(n < 10)
    data = '0' + n;
  else
    data = 'A' + n - 10;
  Serial.println(data);
}
