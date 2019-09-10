package Data

import (
	"fmt"
	//"time"
	"erth/SendFunc"
)
func Print() {
	var slice,Slice []string= SendFunc.Reptile()
	var SLICE []string=SendFunc.Reptile1()
	fmt.Println(slice)
	fmt.Println("\n\n")
	fmt.Println(Slice)
	fmt.Println("\n\n")
	fmt.Println(SLICE)
	
	
	// time.Sleep(time.Duration(100) * time.Second)
	// if SendFunc.Reptile() != slice[0]{
	// 	fmt.Println("earthquakes are occurring on the earth")
	// }else{
	// 	fmt.Println("not earthquake ")
	// }

}