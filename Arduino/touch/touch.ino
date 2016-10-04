#define NUM 100
int f[NUM][5] ,n;
int limit[6] = {5, 5, 5, 8, 4, 3}; //しきい値

void setup(){
  int i, j;
  //モニタリングのためシリアル通信開始
  Serial.begin(9600);
  for(i = 1; i <= 5; i++) {
    //ピンをデジタル出力
    pinMode(i * 2,OUTPUT);
    //ピンをデジタル入力
    pinMode(i * 2 + 1,INPUT);    
  }
  for(i = 0; i < NUM; i++) {
    for(j = 0; j < 5; j++)
      f[i][j] = 0;
  }
  n = 0;
}

void loop(){
 //静電容量変化量の変数を用意
  int i, j, x;
  long int num = 0, digit = 1;
    char data; //送信データ
  
  //指が触れたとき9番ピンがHIGHになるまでをカウント
  for(i = 1; i <= 5; i++) {
    x = 0;
    //ピンをHIGHで出力
    digitalWrite(i * 2, HIGH);
    while (digitalRead(i * 2 + 1)!=HIGH){
      //カウントする
      x++;
      if(x > limit[i])
       break;
    }
    if(x > limit[i]) {
      f[n][i] = 1;
    } else {
      f[n][i] = 0;
    }
    n++;
    n%=NUM;
    
    for(j = 0; j < NUM; j++) {
      if(f[j][i] == 1)
        break;
    }
    if(j != NUM)
      num += digit; 
    digit *= 2;
    //ピンをLOWにする
    digitalWrite(i * 2, LOW);
  }
  if(num < 10)
    data = '0' + num;
  else
    data = 'A' + num - 10;
  Serial.println(data);
}
