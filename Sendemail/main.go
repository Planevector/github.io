package main

import (
	"fmt"
	"send/Sendemail_func"
	"time"
)

type Member struct {
	sister     string
	mother     string
	father     string
	me         string
	girlfriend string
}

func main() {

	V := Member{
		sister:     "today is sister birthday",
		mother:     "today is mother birthday",
		father:     "today is father birthday",
		me:         "today is my birthday",
		girlfriend: "today is girlfriend birthday",
	}
	date := [5]string{"八月廿三", "十一月十五", "五月十六", "十月十五", "六月初五"}

	for {
		var slice []string = Sendemail_func.Reptile()
		switch slice[7] {
		case date[0]:
			Sendemail_func.SendEmail(V.sister)
			fmt.Println("send succes")
		case date[1]:
			Sendemail_func.SendEmail(V.mother)
			fmt.Println("send succes")
		case date[2]:
			Sendemail_func.SendEmail(V.father)
			fmt.Println("send succes")
		case date[3]:
			Sendemail_func.SendEmail(V.me)
			fmt.Println("send succes")
		case date[4]:
			Sendemail_func.SendEmail(V.girlfriend)
			fmt.Println("send succes")
		default:
			fmt.Println("今天没有谁过生日哟")
		}
		time.Sleep(time.Duration(3600) * time.Second)
	}

}

/*
	//fmt.Println(slice)


		var compear string
		compear = slice[7]
		for _, v := range compear {
			fmt.Println(string(v), "\t")
		}
		//	fmt.Println(len(compear))

*/
