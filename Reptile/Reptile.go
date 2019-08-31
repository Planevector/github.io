package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
)

var (
	rePhone = "1[357]\\d{9}"
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

func main() {
	html := GetHtml("http://www.tiaohao.com/news/newshow.asp?idnews=973")
	//fmt.Println(html)

	re := regexp.MustCompile(rePhone)
	allstring := re.FindAllString(html, -1)
	fmt.Println(allstring)
}