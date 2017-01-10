
void setup() 
{
  Serial1.begin(9600);             //Set serial baud rate to 9600
  //Serial.begin(9600);
} 

void loop()
{
  Serial1.println("I'd like to see what's under your Kuiper Belt.");
  delay(3000);
  Serial1.println("Can I dock my rocket at your space station?");
  delay(3000); 
  Serial1.println("Most people believe that if it ain't broke, don't fix it.");
  delay(3000);
  Serial1.println("Engineers believe that if it ain't broke, it doesn't have enough features yet.");
  delay(3000);
}
