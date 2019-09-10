package SendFunc

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"

)


//爬虫

var (
	reId = "<td align=\"center\" style=\"padding-left: 20px\">[0-9]{1,}[.][0-9]</td>"
	Reid =" <td align=\"left\"><a href=\"[a-zA-z]+://[^\\s]*\">[^x00-xff]{1,}</a></td>"
	REID ="<td align=\"center\" style=\"width: 155px;\">{^\\d{4}-\\d{1,2}-\\d{1,2} 10:36:22 }*</td>"

)

func HandleErr(err error, when string) {
	if err != nil {
		fmt.Println(when, er
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
