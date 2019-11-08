#define _pin 8
unsigned long Tempo_Baixo;
unsigned long Tempo_Alto;
int dados[40];
int dadosU[16];
int dadosU1[8];
int dadosU2[8];
int dadosT[16];
int dadosT1[8];
int dadosT2[8];
int dadosSum[8];
int dadosSumTotal[8];
float umid;
float temp;
float Sumid=0;
float Sumtemp=0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Requisição de dados para DHT22
  pinMode(_pin, INPUT_PULLUP);
  delay(1);
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(1);
  pinMode(_pin, INPUT_PULLUP);
  delayMicroseconds(35);

  //Esperando Start do DHT
  while(digitalRead(_pin)==LOW){
    delayMicroseconds(80);
  }
  while(digitalRead(_pin)==HIGH){
    delayMicroseconds(80);
  }

  //Começando a ler
  for(int i=39;i>=0;i--){
    while(digitalRead(_pin)==LOW){
     Tempo_Baixo=micros(); 
    }
    while(digitalRead(_pin)==HIGH){
     Tempo_Alto=micros(); 
    } 
    if((Tempo_Alto-Tempo_Baixo)>65){
      dados[i]=1;
    }else{
      dados[i]=0;
    }
  }
  for(int i=39;i>=0;i--){
    if(i>=32){
      dadosU[i-24]=dados[i];
    }else if(i>=8){
      dadosT[i-8]=dados[i];
    }else{
      dadosSum[i]=dados[i];
    }
  }
  
  Serial.print(dadosSumTotal);
  
  Sumid=0;
  Sumtemp=0;
  for(int i=15;i>=0;i--){
    umid=dadosU[i]*pow(2,i);
    Sumid=Sumid+umid;
    temp=dadosT[i]*pow(2,i);
    Sumtemp=Sumtemp+temp;
  }
  
  Serial.print("Temperatura=");
  Serial.println(Sumtemp*0.1);
  Serial.print("Umidade=");
  Serial.println(Sumid*0.1);
  Serial.print("Temp ");
  for(int i=15;i>=0;i--){
    Serial.print(dadosT[i]);
  }
  Serial.println(" ");
  Serial.print("Umidade ");
  for(int i=15;i>=0;i--){
    Serial.print(dadosU[i]);
  }
  Serial.println(" ");
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
  delay(1000);
}
