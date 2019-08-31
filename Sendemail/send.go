package main

import (
	"gopkg.in/gomail.v2"
)

func main() {

	m := gomail.NewMessage()
	m.SetHeader("From", "planevector@qq.com ")               //发件人
	m.SetHeader("To", "madefullalbum@outlook.com")           //收件人
	m.SetAddressHeader("Cc", "2774905633@qq.com", "message") //抄送人
	m.SetHeader("Subject", "Birthday wishes")                //邮件标题
	m.SetBody("text/html", "today is sister birthday")       //邮件内容

	d := gomail.NewDialer("smtp.qq.com", 465, "planevector@qq.com ", "wonoijpatkildidd")
	//邮件发送 服务器 信息,使用授权码而非密码
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}
}
