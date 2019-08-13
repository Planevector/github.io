package main

import "fmt"

func main(){
{//example one
	sum :=0
	for i :=0;i<100;i++{
		sum+=i
	}
	fmt.Println(sum)
}
{
	//example two
	sum := 1
	for ;sum<1000;{
		sum+=sum
	}
	fmt.Println(sum)
}
{
	//example three
sum :=1 
for sum<1000{
	sum+=10
}
fmt.Println(sum)
}
{
	//example four infinite cycle
	for{
		fmt.Println("1")
		break
	}
}

}