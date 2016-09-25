int f[5];

void setup(){
  int i;
  //モニタリングのためシリアル通信開始
  Serial.begin(9600);
  for(i = 4; i < 5; i++) {
    //ピンをデジタル出力
    pinMode(i * 2,OUTPUT);
    //ピンをデジタル入力
    pinMode(i * 2 + 1,INPUT);    
  }
}

void loop(){
  int limit = 5; //しきい値
 //静電容量変化量の変数を用意
  int i, x;
  long int num = 100000, digit = 10000;
  
  //指が触れたとき9番ピンがHIGHになるまでをカウント
  for(i = 4; i < 5; i++) {
    x = 0;
    //ピンをHIGHで出力
    digitalWrite(i * 2, HIGH);
    while (digitalRead(i * 2 + 1)!=HIGH){
      //カウントする
      x++;
    }
    f[i]+=(x-f[i])/2;
    if(f[i] > limit)
      num += digit;
    digit *= 10;
    //ピンをLOWにする
    digitalWrite(i * 2, LOW);
  }
  Serial.println(num);
}
