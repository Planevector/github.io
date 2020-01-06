package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
)

var (
	rePhone = "[\\s\\S]"
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
	html := GetHtml("https://wenku.baidu.com/view/b1d38878e97101f69e3143323968011ca200f744.html")
	//fmt.Println(html)

	re := regexp.MustCompile(rePhone)
	allstring := re.FindAllString(html, -1)
	fmt.Println(allstring)
}
