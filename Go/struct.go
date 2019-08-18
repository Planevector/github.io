package main

import "fmt"

type Ver struct{
	x int 
	y int 
}



func main(){
	//example one 
	{
fmt.Println(Ver{1,2})
	}
	//example two use points to access fields
	{
		a :=Ver{1,2}
		a.x=4
		fmt.Println(a)

	}
	//example three struct pointer
	{
		a :=Ver{1,2}
		p :=&a
		p.x=10
		fmt.Println(a)
	}
	//struct Grammar
	{
	var(
		a1 =Ver{21,20}
		a2 =Ver{x:22}
		a3 =Ver{}
		p=&Ver{456,123}
		a =p.x
	)
		fmt.Println(a1,a2,a3,p,a)
	}

}