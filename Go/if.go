package main

import "fmt"

func main(){

{
	//example one 
a :=func (x int)int{
if x < 0{
	return -x
}else{
	return x
}
	}
fmt.Println(a(-1))

}

}