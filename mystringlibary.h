

//My strlen
int my_strlen(char name[]){


  int m;

  for(m=0; name[m] != '\0' ; m++){

  }
return m;
}


//my strcmp

int my_strcmp(char str1[], char str2[]){
  int b = 0;
int n ;


if(my_strlen(str1) == my_strlen(str2)){
  for(n = 0 ;  ((str1[n] != '\0') && (b == 0)) ;){

    if(str1[n] == str2[n]){
      b = 0;
      n++;


    }
    else if(str1[n] <= str2[n]){
      b = -1;

    }
    else if(str1[n] >= str2[n]){

      b = 1;
    }

    }
}
else if(my_strlen(str1) < my_strlen(str2)){

  b = -1;

}

else if(my_strlen(str1) > my_strlen(str2)){

b = 1;

}
return b;
}

//my strcpy

void my_strcpy(char str6[], char str7[]){


  int v;
  int c;
  int l;
   if((my_strlen(str6) >= my_strlen(str7)) && (my_strlen(str6) != 0)){

  for(v = 0 ; str6[v] != '\0' ; v++){

  str6[v] = str7[v];

    }
    }

     if(my_strlen(str6) < my_strlen(str7)){

  for(c = my_strlen(str7) ; c > -1 ; c--){

  l = my_strlen(str7);
  str6[l];

  str6[c] = str7[c];


  }





  }



}



void my_strcat(char str41[], char str42[]){


int lenstr1;//y
int z;
int u;
int o;
int f;
int lenstr2=my_strlen(str42);
lenstr1 = my_strlen(str41);
lenstr2 =  my_strlen(str42);
z = lenstr1 + lenstr2;

char resultstr[z];



my_strcpy(resultstr, str41);


int deneme=0;
for(int i =lenstr1 ; i <z;i++){
  resultstr[i]=str42[deneme];
  deneme++;
  if (deneme == lenstr2){
    resultstr[z]='\0';
    break;
  }
}
printf("%s", resultstr);







}
