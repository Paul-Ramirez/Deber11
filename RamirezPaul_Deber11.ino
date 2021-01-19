/*
 * APRENDIZAJE DE MAQUINA-REGRESION EXPONENCIAL
 * DEBER #11
 * OBJETIVO: GENERAR MODELO DE REGRESION EXPONENCIAL-recibir datos por cx
 * Fecha: 18/01/2021
 * Nombre: Ramirez Paul
 * Formulas: y=Ae^(Bx)
 *           y'=A'+Bx
 *           ----------Bo=(n(Exy')-(Ex)(Ey'))/(n*Ex^2-(Ex)^2)-----
 *           ----------A'= M(Ey')-Bo(M(Ex))
 *           ----------A=exp(A')
 */
//matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};
int col=0;//moverse en columnas
int fil=0;//moverse en filas
float Elog_Y=0;//sumatoria log de y
int Ex=0;//sum de x
int Ey=0;//sum de y
float logA;//log de A
float Exy=0;//sumatoria de xy
long int Ex2=0;//sum de x^2
long int Ex_2=0;//sum de sum de x al cuadrado
int n=14;//tamaño de muestras
float Bo;//ordenada en el origen
float A;//resultado
String dato;//recibir estatura
int estatura;//convertir dato
float peso;
float m1=0;//aux

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    //Ey=Ey+matriz[fil][1];
    Elog_Y=Elog_Y+log(matriz[fil][1]);
    Exy=Exy+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  Bo=(float(n*Exy)-float(Ex*Elog_Y))/(float(n*Ex2)-float(Ex_2));
  m1=Bo*(Ex/n);//aux de desborde
  logA=float(Elog_Y/n)-float(m1);
  A=float(exp(logA));
  Serial.println("El modelo es:");
  Serial.println(String("y = ")+String(A)+String("*")+String("e^(")+String(Bo)+String("*x)"));
  Serial.println("Ingrese su estatura: ");

}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=A*exp(Bo*estatura);
    Serial.println(" ");
    Serial.println(String("Su peso es: ")+String(peso)+String("kg"));
    Serial.println("Ingrese su estatura: ");
  }
}
