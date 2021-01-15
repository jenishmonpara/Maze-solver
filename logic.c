const int lmf,lmb,rmf,rmb;
const int trigl;
const int echol;
const int trigr;
const int echor;
const int trigs;
const int echos;
float dist;
long int duration;
char path[500],pmo[500],pro[3]={'l','s','r'};//pathmorethanone and priority order
int pl=0,f=0;//path counter and flag for deadend
int pmoc=0;//pathmorethanone counter
#define md 5



void setup() 
{
pinMode(trigl, OUTPUT); // Sets the trigPin as an Output
pinMode(echol, INPUT);
pinMode(trigr, OUTPUT); // Sets the trigPin as an Output
pinMode(echor, INPUT);
pinMode(trigs, OUTPUT); // Sets the trigPin as an Output
pinMode(echos, INPUT);
Serial.begin(9600);
}

void turn(char t)
{
  
}
void uturn()
{
  
  f++;
}
float ldist()
{
 // Clears the trigPin
digitalWrite(trigl, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigl, HIGH);
delayMicroseconds(10);
digitalWrite(trigl, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echol, HIGH);

// Calculating the distance
distance= duration*0.034/2;
return distance; 
  
}
float rdist()
{
  // Clears the trigPin
digitalWrite(trigr, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigr, HIGH);
delayMicroseconds(10);
digitalWrite(trigr, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echor, HIGH);

// Calculating the distance
distance= duration*0.034/2;
return distance;
  
}
float sdist()
{
  // Clears the trigPin
digitalWrite(trigs, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigs, HIGH);
delayMicroseconds(10);
digitalWrite(trigs, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echos, HIGH);

// Calculating the distance
distance= duration*0.034/2;
return distance;
  
}

void loop() 
{
if(ldist()<md && rdist()<md && sdist()>md)
  turn('s'),path[pl++]='s';

else if(ldist()<md && rdist()<md && sdist()<md)
    {
      uturn();path[pl++]='u';
    }

    
else if (ldist()>md && rdist()<md && sdist()<md) 
{ turn('l');
path[pl++]='l';
  
 } 
 else if (ldist()<md && rdist()>md && sdist()<md)
 {
  turn('r');path[pl++]='r';

 }




else if(ldist()>md && rdist()<md && fdist()>md)
{
if(f)
{
  if(pmo[pmoc-1]=='s')
  {
    turn('l');path[pl++]='l';pmo[pmoc++]='l'; f--;
  }else
  {
    turn('s');path[pl++]='s';pmo[pmoc++]='s'; f--;
  }
}

else
{
  
  int cnt=0;
  while(pro[cnt]!='l' || pro[cnt]!='s')
  {
      cnt++;
  }
  turn(pro[cnt]);path[pl++]=pro[cnt];pmo[pmoc++]=pro[cnt];
}
}

else if(ldist()>md && rdist()>md && fdist()<md)
{

if(f)
{
  if(pmo[pmoc-1]=='r')
  {
    turn('r');path[pl++]='r';pmo[pmoc++]='r'; f--;
  }else
  {
    turn('l');path[pl++]='l';pmo[pmoc++]='l'; f--;
  }
}

else
{  
  int cnt=0;
  while(pro[cnt]!='l' || pro[cnt]!='r')
  {
      cnt++;
  }
  turn(pro[cnt]);path[pl++]=pro[cnt];pmo[pmoc++]=pro[cnt];
}
}


else if(ldist()<md && rdist()>md && fdist()>md)
{

if(f)
{
  if(pmo[pmoc-1]=='s')
  {
    turn('l');path[pl++]='l';pmo[pmoc++]='l'; f--;
  }else
  {
    turn('s');path[pl++]='s';pmo[pmoc++]='s'; f--;
  }
}
}

else
{  
  int cnt=0;
  while(pro[cnt]!='r' || pro[cnt]!='s')
  {
      cnt++;
  }
  turn(pro[cnt]);path[pl++]=pro[cnt];pmo[pmoc++]=pro[cnt];
}
}


else if(ldist()>md && rdist()>md && fdist()>md)
{
 if(f)
 {
  if(pmo[pmoc-1]=='s' && pro[0]=='s')
  {
    turn(pro[1]);path[pl++]=pro[1];pmo[pmoc++]=pro[1]; f--;
  }else
  {
    turn(pro[0]);path[pl++]=pro[0];pmo[pmoc++]=pro[0]; f--;
  }

    if(pmo[pmoc-1]=='r' && pro[0]=='l')
  {
    turn(pro[1]);path[pl++]=pro[1];pmo[pmoc++]=pro[1]; f--;
  }else
  {
    turn(pro[0]);path[pl++]=pro[0];pmo[pmoc++]=pro[0]; f--;
  }

  if(pmo[pmoc-1]=='l' && pro[0]=='r')
  {
    turn(pro[1]);path[pl++]=pro[1];pmo[pmoc++]=pro[1]; f--;
  }else
  {
    turn(pro[0]);path[pl++]=pro[0];pmo[pmoc++]=pro[0]; f--;
  }
  

  
  
 }

  else
  {
  turn(pro[0]);path[pl++]=pro[0];pmo[pmoc++]=pro[0];
  }
}




if(path[pl]==path[pl-1] && path[pl-1]==path[pl-2] && path[pl-2]==path[pl-3] && pl>2)
{
  pl=pl-3;char temp=pro[0];
  pro[0]=pro[1];pro[1]=pro[2];pro[2]=temp;
}


 



}
