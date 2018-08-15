// Command Line Programming


int num1,num2,sum=0;
    if(argc<1)
    {
        printf("Invalid command line");
    }
    num1=atoi(argv[1]);
    num2=atoi(argv[2]);
    sum=num1+num2;
    printf("%d",(sum));
    
