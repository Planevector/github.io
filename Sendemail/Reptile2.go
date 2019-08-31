package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"regexp"
)

var (
	reEmail = "[\\w\\.]+@\\w+\\.[a-z]{2,}"
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
	html := GetHtml("http://dq.tieba.com/p/5943503658")
	re := regexp.MustCompile(reEmail)
	allstring := re.FindAllString(html, -1)
	fmt.Println(allstring)
}
