	/*commonly used types
	bool
	string 
	int int8 int16 int32 int64
	uint ... ...uintptr
	byte == uint 8
	rune == int 32
	float32 float64
	complex64 complex128
*/

package main

import (
	"fmt"
)

func main(){
{
	
	//the variable value without an explicit initial values is 0 
	var i int 
	var f float64
	var b bool
	var s string
	fmt.Println(i,f,b,s)
}

{
	//type conversion
	var i int = 42
	var f float64 = float64(i)+.4
	fmt.Println(f,i)
	//smiple method
	a :=43
	b :=float64(i)+0.5
	fmt.Println(a,b)
	//When declaring a variable without specifying the type, the variable's
	

}

}