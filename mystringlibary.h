int my_strlen(char name[]){


  int m;

  for(m=0; name[m] != '\0' ; m++){

  }
return m;
}




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


int lenstr1;
int z;
int i;
int lenstr2 = my_strlen(str42);
lenstr1 = my_strlen(str41);

z = lenstr1 + lenstr2;

char resultstr[z];



my_strcpy(resultstr, str41);


int deneme=0;
for(i = lenstr1 ; i < z ; i++){
  resultstr[i] = str42[deneme];
  deneme++;
  if (deneme == lenstr2){
    resultstr[z]='\0';
    break;
  }
}
my_strcpy(str41, resultstr);







}
void my_strncat(char str41[], char str42[], int n){


int lenstr1;
int z;
int i;
int lenstr2 = my_strlen(str42);
lenstr1 = my_strlen(str41);

z = lenstr1 + n;

char resultstr[z];




my_strcpy(resultstr, str41);


int deneme = 0;

if(lenstr2 == n){

  my_strcat(str41, str42);
}

else if(lenstr2 < n){

  my_strcat(str41, str42);
}



else if(lenstr2 > n){

my_strcat(str41, str42);


str41[lenstr1 + n] = '\0';

}



}



void my_strncpy(char str1[], char str2[], int n){


if(n >= my_strlen(str2)){

my_strcpy(str1, str2);
}

else if(n < my_strlen(str2)){

my_strcpy(str1, str2);

str1[n] = '\0';

}




}




int my_strncmp(char str1[], char str2[], int n){


if(my_strlen(str1) == my_strlen(str2)){

if(my_strcmp(str1, str2) == 0){
  return my_strcmp(str1, str2);
}
else if(n > my_strlen(str1)){

  return my_strcmp(str1, str2);
}
else if(n < my_strlen(str1)){

  str1[n] = '\0';
  str2[n] = '\0';
  return my_strcmp(str1, str2);
}
else if((n ==  my_strlen(str1)) && my_strcmp(str1, str2) != 0){

  return my_strcmp(str1, str2);
}
}

//7///////////////////
else if(my_strlen(str1) < my_strlen(str2)){


if(n <= my_strlen(str1)){
  str1[n] = '\0';
  str2[n] = '\0';
  return my_strcmp(str1, str2);

}
else if(my_strlen(str1) < n < my_strlen(str2)){

str2[n] = '\0';

return my_strcmp(str1, str2);

}

else if(n >= my_strlen(str2)){

  return my_strcmp(str1, str2);

}



}

/////////////////


else if(my_strlen(str1) > my_strlen(str2)){


if(n <= my_strlen(str2)){

str1[n] = '\0';
str2[n] = '\0';
return my_strcmp(str1, str2);

}
else if(my_strlen(str2) < n < my_strlen(str1)){

str1[n] = '\0';

return my_strcmp(str1, str2);


}

else if(my_strlen(str1) <= n){

return my_strcmp(str1, str2);


}



}











}
