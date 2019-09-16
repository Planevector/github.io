package main

import (
	"fmt"
	"time"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
	"gopkg.in/gomail.v2"
)
type Member struct {
	sister     string
	mother     string
	father     string
	me         string
	girlfriend string
}

func main(){
	for {
		Data()
	}
}

func Data(){

	V := Member{
		sister:     "today is sister birthday",
		mother:     "today is mother birthday",
		father:     "today is father birthday",
		me:         "today is my birthday",
		girlfriend: "today is girlfriend birthday",
	}
	date := [5]string{"八月廿三", "十一月十五", "五月十六", "十月十五", "六月初五"}

	for {
		var slice []string = Reptile()
		switch slice[7] {
		case date[0]:
			SendEmail(V.sister)
			fmt.Println("send succes")
		case date[1]:
		SendEmail(V.mother)
			fmt.Println("send succes")
		case date[2]:
			SendEmail(V.father)
			fmt.Println("send succes")
		case date[3]:
			SendEmail(V.me)
			fmt.Println("send succes")
		case date[4]:
			SendEmail(V.girlfriend)
			fmt.Println("send succes")
		default:
			fmt.Println("今天没有谁过生日哟")
			fmt.Println("today is",slice[7])
		}
		time.Sleep(time.Duration(7200) * time.Second)
	}


}
func SendEmail(Member string) {

	m := gomail.NewMessage()
	m.SetHeader("From", "bandicam2017@aliyun.com")              //发件人
	m.SetHeader("To", "planevector@qq.com")                    //收件人
	m.SetAddressHeader("Cc", "planevector@163.com", "message") //抄送人
	m.SetHeader("Subject", "家人生日祝福提醒")                         //邮件标题
	m.SetBody("text/html", Member)                             //邮件内容
	d := gomail.NewDialer("smtp.aliyun.com", 465, "bandicam2017@aliyun.com", "Wang1015")
	//邮件发送 服务器 信息,使用授权码而非密码
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}
}

//爬虫

var (
	reId = "[\u4e00-\u9fa5]月[\\s\\S]{1,2}"
)

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

func Reptile() []string {

	var s []string
	html := GetHtml("https://www.jintianjihao.com")

	//fmt.Println(html)

	re := regexp.MustCompile(reId)
	s = re.FindAllString(html, -1)
	return s

	//fmt.Println(s)
}