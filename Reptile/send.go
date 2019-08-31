package main

import (
	"gopkg.in/gomail.v2"
)

func main() {
	send("hello"+"你好"+"世界")
}

func send(text string) {
	m := gomail.NewMessage()
	m.SetHeader("From", "planevector@aliyun.com")              //发件人
	m.SetHeader("To", "planevector@qq.com")                    //收件人
	m.SetAddressHeader("Cc", "planevector@163.com", "message") //抄送人
	m.SetHeader("Subject", "Birthday wishes")                  //邮件标题
	m.SetBody("text/html", text)                               //邮件内容

	d := gomail.NewDialer("smtp.aliyun.com", 465, "planevector@aliyun.com", "Wang1015")
	//邮件发送 服务器 信息,使用授权码而非密码
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}
}
