package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
)

var (
	reId = "<p class=\"topTimeBlue\">[\\s\\S]+?月[\\s\\S]{1,2}</p>"
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
	html := GetHtml("https://www.jintianjihao.com")

	//fmt.Println(html)

	re := regexp.MustCompile(reId)
	allstring := re.FindAllString(html, -1)
	var i int
	for range allstring {
		fmt.Println(allstring[i])
		i++
	}
	//fmt.Println(allstring)

}
