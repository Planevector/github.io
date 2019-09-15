package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
	"time"
	"gopkg.in/gomail.v2"

)

func main(){
	
for {
	Print()
}
	// var i int
	// for range slice{
	// 	fmt.Println(slice[i])
	// 	i++
	// }
	
}


//sendemail

func Send(Member []string,Member2 []string,Member3 []string) int {

	m := gomail.NewMessage()
	m.SetHeader("From", "bandicam2017@aliyun.com")              //发件人
	m.SetHeader("To", "1171840237@qq.com")                    //收件人
	m.SetAddressHeader("Cc", " ", "message") //抄送人
	m.SetHeader("Subject", "earthquake warning")                         //邮件标题
	m.SetBody("text/html", "时间"+Member[0]+"地点"+Member2[0]+"地震等级"+Member3[0])                             //邮件内容
	d := gomail.NewDialer("smtp.aliyun.com", 465, "bandicam2017@aliyun.com", "Wang1015")
	//邮件发送 服务器 信息,使用授权码而非密码
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}
	return 1
}


//爬虫

var (
	reId = "<td align=\"center\" style=\"padding-left: 20px\">[0-9]{1,}[.][0-9]</td>"//earthquake
	Reid =" <td align=\"left\"><a href=\"[a-zA-z]+://[^\\s]*\">[^x00-xff]{1,}</a></td>"//localtion
	REID ="<td align=\"center\" style=\"width: 155px;\">[\\s\\S]*?</td>"//time

)

//<td align="center" style="width: 155px;">2019-09-11 07:32:25</td>

func HandleErr(err error, when string) {
	if err != nil {
		fmt.Println(when, err)
		os.Exit(1)
	}
}

func GetHtml(url string) string {
	resp, err := http.Get(url)
	HandleErr(err, url)
	bytes, _ := ioutil.ReadAll(resp.Body)
	html := string(bytes)

	return html
}
func Reptile1() []string{
	html := GetHtml("http://news.ceic.ac.cn/index.html?time=1567954189")

	//fmt.Println(html)
	var s []string
	re := regexp.MustCompile(REID)
	s = re.FindAllString(html, -1)

	return s
}

func Reptile() ([]string,[]string){

	html := GetHtml("http://news.ceic.ac.cn/index.html?time=1567954189")

	//fmt.Println(html)
	var s []string
	var S []string
	re := regexp.MustCompile(reId)
	s = re.FindAllString(html, -1)
	Re :=regexp.MustCompile(Reid)
	S = Re.FindAllString(html,-1)

	return s,S

	//fmt.Println(s,"\n")
}



func Print() {
	var earthquake,localtion []string= Reptile()
	var Time []string=Reptile1()
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
	 v :=Reptile1()
	// switch SLICE[0]{
	// case  v[0] :fmt.Println("it's not earthquake")
	// 	 default :fmt.Println("warning earthquake")
	// }

	if Time[0]==v[0]{
		  fmt.Println("\n")
		  fmt.Println(v[0])
		fmt.Println("it's not earthquake")
		
	}else{
		if 1==Send(Time,localtion,earthquake){
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
