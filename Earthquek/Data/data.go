package Data

import (
	"fmt"
	"time"
	"erth/SendFunc"
)
func Print() {
	var earthquake,localtion []string= SendFunc.Reptile()
	var Time []string=SendFunc.Reptile1()
	fmt.Println("last earthquake\n")
	fmt.Println(Time[0])
	fmt.Println(localtion[0])
	fmt.Println(earthquake[0])
	time.Sleep(time.Duration(50) * time.Second)
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

	if Time[0]==v[0]{
		  fmt.Println("\n")
		  fmt.Println(v[0])
		fmt.Println("it's not earthquake")
		
	}else{
		if 1==SendFunc.Send(Time,localtion,earthquake){
			fmt.Println("send success")
		}
	}

	
	
	// time.Sleep(time.Duration(100) * time.Second)
	// if SendFunc.Reptile() != slice[0]{
	// 	fmt.Println("earthquakes are occurring on the earth")
	// }else{
	// 	fmt.Println("not earthquake ")
	// }

}