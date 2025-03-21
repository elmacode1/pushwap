// create a fct that takes a string of integers and returns an array

// input: ./a.out "  14 421 3 4" output:[1,21,3,4]    
#include <stdio.h>
#include <stdlib.h>
int countdigits (char *str){
        int i=0;
        int count=0;
        while(str[i]){
                while(!((str[i]>='0' && str[i]<='9'))&&str[i])
                        i++;
                while(str[i]>='0' && str[i]<='9' && str[i])
                        i++;
                i--;
                if(str[i]>='0' && str[i]<='9' && str[i])
                        count++;
                i++;
        }
        return count;
}
int ft_atoi(char *str){
        int i=0;
        int sign=1;
        int result=0;
        while (str[i] == ' ' || ((str[i] >= 9 && str[i] <= 13) && str[i]))
		        i++;
        if (str[i]=='-'  || str[i]=='+'){
                if (str[i]=='-'){
                        sign*=-1;
                        i++;
                }
        } 
        while (str[i]>='0' && str[i]<='9' && str[i]){
                result *= 10;
                result+= (str[i] - '0');           
                i++;
        }
        return result*sign;
}
int *ctoi (char *s){
        int *ptr;
        int i=0;
        int j=0;
        ptr = malloc((sizeof(int))*countdigits(s));
        while(s[i]){
                ptr[j]=ft_atoi(&s[i]);
                j++;
                while(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)&& s[i])
                        i++;
                while( (s[i]>='0'&&s[i]<='9') || (s[i]=='-' || s[i]=='+') && s[i])
                i++;
        }
        return ptr;
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int digits(char *str){
        int i=0;
        while(str[i]){
                while (str[i] == ' ' || ((str[i] >= 9 && str[i] <= 13) && str[i]))
		        i++;
                if(str[i]=='+' || str[i]=='-')
                        i++;
                while(str[i]>='0'&&str[i]<='9' && str[i])
                        i++;
                if(!((str[i]>='0'&&str[i]<='9') || str[i]==' ')  && str[i])
                        return 0;
                if(!str[i])
                        break;        
                i++;
        }
        return 1;
}


int main(int ac,char **av){
       int i=1;
       char *result;
       int *ptr;
       if (ac > 1){
        while (ac  > i){
                if (digits(av[i])== 0){
                       printf("Error");
                       return 0;
                }
                i++;
        }
        result=av[1];
        i = 2;
        while(ac > i){
                result = ft_strjoin(result," ");
                result = ft_strjoin(result,av[i]);
                i++;
        }
        ptr = ctoi(result);
        i=0;
        while(i<7)
        {
                printf("%d,",ptr[i]);
                i++;
        }
        //to do: check for any doubles
       }
}

