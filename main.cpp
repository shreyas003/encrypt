/*NOTES:
1. change the division op in encrypt to sumthing else or fix it.
2. masking or charset
3. the operations sometime go out of bounds, creating problems during decoding
3 has been fixed by doing simpler ops with random numbers thrown in*/


#include <iostream>
#include <cmath>



using namespace std;

int input=0;
int prkey[10];
int pubkey[10];
char data[100];
char edata[100];
char ddata[100];

void encrypt();
void encryption_key();
void decrypt();

int main()
{
    cout<<"Please enter data to be encrypted"<<endl;
    cin>>data;

    cout<<"Enter encryption key\n";
    cin>>input;

    cout<<endl<<"encryption key is\n";
    for (int i = 2; i >= 0; i--)
    {
        prkey[i] = input % 10;
        input /= 10;
    }

    for(int i=0;i<3;i++)
    {
         cout<<prkey[i];
    }

    cout<<endl;



    encryption_key();

    cout<<"\nthe public key is\n";

    for(int i=0;pubkey[i]!='\0';i++)
    {
        cout<<pubkey[i];
    }

    cout<<endl;

    encrypt();
    cout<< "\nthe encrypted data is"<<endl<<edata;

    decrypt();
    cout<<endl<<endl<<"the decrypted data is"<<endl<<ddata;


    return 0;
}

void encryption_key()
{
    int i=0;

    for(i=0;prkey[i]!='\0';i++)
    {
        pubkey[i] = prkey[i];

        pubkey[i] = int(round((pubkey[i]*2)/4));

    }

}

void encrypt()
{
    int i=0;
    int j=0;
    for(j=0,i=0;j<3,data[i]!= NULL;j=(j+1)%3,i++)
    {

            edata[i]=data[i]-prkey[j];
            //cout<<edata[i]<<endl;

            edata[i]=edata[i]-4;
            //edata[i]=(edata[i]-54)*prkey[j];
            //cout<<edata[i]<<endl;

            //edata[i]=((edata[i]-10)*2);

            edata[i]=edata[i]+(2*prkey[j]);
            //cout<<edata[i]<<endl;

            edata[i]=edata[i]-13;

            //edata[i]= (edata[i])>>1;

            //edata[i]= (edata[i]*prkey[j])-2;

            //edata[i] = edata[i]*2;

            edata[i]=edata[i]-(prkey[j]);
            //cout<<edata[i]<<endl;

            //cout<<"ERROR"<<endl;
    }



}

void decrypt()
{



        int i=0;
        int j=0;
        for(j=0,i=0;j<3,edata[i]!= NULL;j=(j+1)%3,i++)
        {

            ddata[i]=edata[i]+(prkey[j]);

            //ddata[i]=ddata[i]/2;

        //ddata[i]= (ddata[i]+2)/prkey[j];

        //ddata[i] = (ddata[i])<<1;

            ddata[i]=ddata[i]+13;

            ddata[i]=ddata[i]-(2*prkey[j]);


        //ddata[i]=ddata[i]-9;
            //ddata[i]=(ddata[i]/2)+10;

            ddata[i]=ddata[i]+4;

            ddata[i]=ddata[i]+ prkey[j];
        }


}





/*int main()
{
   int i, x;
   char str[100];
   char estr[100];
   int key[5];


   cout << "Please enter a string:\t";
   cin >> str;

   cout<<"enter key:\t";
   cin>> key[5];

   cout << "\nPlease choose following options:\n";
   cout << "1 = Encrypt the string.\n";
   cout << "2 = Decrypt the string.\n";
   cin >> x;

   //using switch case statements
   switch(x)
   {
      //first case for encrypting a string
      case 1:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
         {
            estr[i] = str[i] + key[i];
            estr[i] = estr[i] + (key[i]+1);
         }

         cout << "\nEncrypted string: " << estr << endl;
         break;

      //second case for decrypting a string
      case 2:
         for(i = 0; (i < 100 && str[i] != '\0'); i++)
         {
            estr[i] = str[i] - (key[i]+1);
            estr[i] = estr[i] - key[i]; //the key for encryption is 3 that is subtracted to ASCII value
         }

         cout << "\nDecrypted string: " << estr << endl;
         break;


      default:
         cout << "\nInvalid Input !!!\n";


   }

   return 0;
}*/






