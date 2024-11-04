#include<stdio.h>
float mean(int size, float data[size])
{
    float t;
    for(int i = 0; i < size; i++)
    {
        t += data[i];
    }
    t=t/size;
    return t;
}
float median(int size, float data[size])
{
    if (size %2 !=0 )
        return data[(size-1)/2];
    else
        return (data[size/2]+data[size/2-1])/2;
}
float mode(int size, float data[size])
{
    int flag[size];
    for(int i = 0; i < size; i++) // initializing all flag values to 0
    {
        flag[i]=0;
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j <size; j++)
        {
            if(data[i]==data[j])
                flag[i]+=1;   
        }
    }
    int max=0;
    for(int i = 0; i < size; i++)
    {
        if(i==0)
            max=flag[0];
        else if(flag[i]>flag[i-1])
            max = flag[i];
    }
    for(int i = 0; i < size; i++)
    {
        if (flag[i]==max)
            return data[i];
    }
}
void main()
{
    float *data; int size;
    printf("How many entries: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        scanf("%f", data +i);
    }
    printf("The mean is %f\n", mean(size, data));
    printf("The median is %f\n", median(size, data));
    printf("The mode is %f\n", mode(size, data));
    
}