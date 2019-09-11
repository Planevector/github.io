package SendFunc

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
	"gopkg.in/gomail.v2"
)

//sendemail

func Send(Member []string,Member2 []string,Member3 []string) {

	m := gomail.NewMessage()
	m.SetHeader("From", "planevectot@aliyun.com")              //发件人
	m.SetHeader("To", "planevector@qq.com")                    //收件人
	m.SetAddressHeader("Cc", "planevector@163.com", "message") //抄送人
	m.SetHeader("Subject", "earthquake warning")                         //邮件标题
	m.SetBody("text/html", Member[0]+Member2[0]+Member3[0])                             //邮件内容
	d := gomail.NewDialer("smtp.aliyun.com", 465, "planevectotzc@aliyun.com", "Wang1015")
	//邮件发送 服务器 信息,使用授权码而非密码
	if err := d.DialAndSend(m); err != nil {
		panic(err)
	}
}


//爬虫

var (
	reId = "<td align=\"center\" style=\"padding-left: 20px\">[0-9]{1,}[.][0-9]</td>"
	Reid =" <td align=\"left\"><a href=\"[a-zA-z]+://[^\\s]*\">[^x00-xff]{1,}</a></td>"
	REID ="<td align=\"center\" style=\"width: 155px;\">[\\s\\S]*?</td>"

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
