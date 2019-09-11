package Data

import (
	"fmt"
	"time"
	"erth/SendFunc"
)
func Print() {
	var slice,Slice []string= SendFunc.Reptile()
	var SLICE []string=SendFunc.Reptile1()
	fmt.Println("\n")
	fmt.Println(SLICE[0])
	time.Sleep(time.Duration(500) * time.Second)
	// fmt.Println(slice)
	// fmt.Println("\n\n\n")
	// fmt.Println(Slice)
	// fmt.Println("\n\n\n")
	// fmt.Println(SLICE)
	 v :=SendFunc.Reptile1()
	// switch SLICE[0]{
	// case  v[0] :fmt.Println("it's not earthquake")
	// 	 default :fmt.Println("warning earthquake")
	// }

	if SLICE[0]==v[0]{
		  fmt.Println("\n")
		  fmt.Println(v[0])
		fmt.Println("it's not earthquake")
		
	}else{
		SendFunc.Send(Slice,SLICE,slice)
	}

	
	
	// time.Sleep(time.Duration(100) * time.Second)
	// if SendFunc.Reptile() != slice[0]{
	// 	fmt.Println("earthquakes are occurring on the earth")
	// }else{
	// 	fmt.Println("not earthquake ")
	// }

}