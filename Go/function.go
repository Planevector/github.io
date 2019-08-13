package main

import "fmt"
//example one
func add(x int ,y int) int{
	return x+y
}

//example two

func a_dd(x ,y int)int{
	return x+y
}

//example three returns multiple values

func swap(x,y string) (string,string){
	return y,x
}

func main(){
fmt.Println("exaple one",add(12,21))
fmt.Println("exaple two",a_dd(12,33))
a,b :=swap("ok","are you")
fmt.Println("exaple three",a,b)
}