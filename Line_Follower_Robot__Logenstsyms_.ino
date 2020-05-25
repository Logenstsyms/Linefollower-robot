/*
 * --------------------------------------------------------------------------------------------------------------------
 * Logenstsyms Youtube сувагт нэгдсэнд баярлалаа. 
 * Subscribe дархаа бүү мартаарай.
 * 
 *                    Хүндэтгэсэн: П.Жавхлантөгс
 *                             Танд амжилт хүсье.
 * --------------> Робот булан <--> Зураас дагагч роботын код <-------------------------
 * 
 * 
 */
  
    #define E1 11   // Мотор нэгийн  хурдны pwm хөлыг E1 гэж зарлаад 11-р хөлтэй холбох
    #define E2 5    // Мотор хоёрын  хурдны pwm хөлыг E2 гэж зарлаад 5-р хөлтэй холбох
    #define R_1 10  // Мотор нэгийн чиглэл А
    #define R_2 9   // Мотор нэгийн чиглэл Б
    #define L_1 8   // Мотор хоёрын чиглэл А
    #define L_2 7   // Мотор хоёрын чиглэл Б
    
    #define sensor1 A0 // мэдрэгч нэгийг sensor1 гэж зарлаад А0-р хөлтэй холбох
    #define sensor2 A1 // мэдрэгч хоёрыг sensor2 гэж зарлаад А1-р хөлтэй холбох
    
    volatile int s1 = 0,s2 = 0; //Мэдрэгчийн утга хадгалах хаяг.

void setup()
{
  
   Serial.begin(9600);  //Сериалаар хэвлэх хурд 9600

   pinMode(E1, OUTPUT);  //E1-г гаралт болгон зарлав
   pinMode(E2, OUTPUT);  //E2-г гаралт болгон зарлав
   pinMode(L_1, OUTPUT); //L_1-г гаралт болгон зарлав
   pinMode(L_2, OUTPUT); //L_2-г гаралт болгон зарлав
   pinMode(R_1, OUTPUT); //R_1-г гаралт болгон зарлав
   pinMode(R_2, OUTPUT); //R_2-г гаралт болгон зарлав

   pinMode(sensor1, INPUT_PULLUP);  //sensor1-ыг оролт болгон зарлав
   pinMode(sensor2, INPUT_PULLUP);  //sensor2-ыг оролт болгон зарлав

}

void loop()
{

    s1 = digitalRead(sensor1);// sensor1-н утгийг s1т хадгалах
    s2 = digitalRead(sensor2);// sensor2-н утгийг s2т хадгалах
      
    Serial.print(s1);     //s1-ын утгийг сериалаар хэвлэх
    Serial.print("  ");   //Зай авах
    Serial.println(s2);   //s2-ын утгийг сериалаар хэвлэх

if(s1==0 && s2==0)    //Хэрэв s1, s2 цагаан өнгө мэдэрсэн тохиолдолд дараак комманд биелнэ.
{
       digitalWrite(R_2,0);
       digitalWrite(L_2,0);
       digitalWrite(R_1,1);
       digitalWrite(L_1,1);
       analogWrite(E1,0);
       analogWrite(E2,0);
}

if(s1==1 && s2==1)   //Хэрэв s1, s2 хар өнгө мэдэрсэн тохиолдолд дараак комманд биелнэ.
{
       digitalWrite(R_2,0);
       digitalWrite(L_2,0);
       digitalWrite(R_1,1);
       digitalWrite(L_1,1);
       analogWrite(E1,250);  //230
       analogWrite(E2,250);  //210
}


if(s1==0 && s2==1)   //Хэрэв s1 цагаан өнгө, хар цагаан өнгө мэдэрсэн тохиолдолд дараак комманд биелнэ.
{
       digitalWrite(R_2,0);
       digitalWrite(L_2,0);
       digitalWrite(R_1,1);
       digitalWrite(L_1,1);
       analogWrite(E1,100);
       analogWrite(E2,250);
}

if(s1==1 && s2==0)    //Хэрэв s1 хар өнгө, s2 цагаан өнгө мэдэрсэн тохиолдолд дараак комманд биелнэ.
{
       digitalWrite(R_2,0);
       digitalWrite(L_2,0);
       digitalWrite(R_1,1);
       digitalWrite(L_1,1);
       analogWrite(E1,250);
       analogWrite(E2,100);
}
}
