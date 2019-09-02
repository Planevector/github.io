package Sendemail_func

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
	"gopkg.in/gomail.v2"
)

//发送邮件
func SendEmail(Member string) {

	m := gomail.NewMessage()
	m.SetHeader("From", "planevectot@aliyun.com")              //发件人
	m.SetHeader("To", "planevector@qq.com")                    //收件人
	m.SetAddressHeader("Cc", "planevector@163.com", "message") //抄送人
	m.SetHeader("Subject", "家人生日祝福提醒")                         //邮件标题
	m.SetBody("text/html", Member)                             //邮件内容
	d := gomail.NewDialer("smtp.aliyun.com", 465, "planevectotzc@aliyun.com", "Wang1015")
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
