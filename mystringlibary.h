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
