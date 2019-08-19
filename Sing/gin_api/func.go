package gin_api

import (
    . "https/data"
    Func "https/func_judge"
    "net/http"

    "github.com/gin-gonic/gin"
)
func Register(c *gin.Context){
	UserName :=c.Request.FormValue("Name")
	PassWord :=c.Request.FormValue("Passwd")

	Bool :=Func.IsExist(UserName)
	if Bool{
		State["state"]=1
		State["text"]="user already exists"	
	}else{
		AddStruct(UserName,PassWord)
		State["state"]=1
		State["text"]="login was successful"
	}
	
	c.String(http.StatusOk,"%v",State)

}

func Login(c *gin.Context){
	UserName :=c.Request.FormValue("Name")
	PassWord :=c.Request.FormValue("Passwd")

	Bool :=Fucn.IsExist(UserName)
	if Bool{
		Bool_Pwd :=Func.IsRight(UserName,PassWord)
		if Bool_Pwd{
			State["state"]="1"
			State["text"]="sing was successful"
		}else{
			State["state"]=0
			State["text"]="Password Error"
		}
	}else{
		State["state"]=2
		State["text"]="login fail user not registered"
	}
	c.String(http.StatusOk,"%v",State)

}

func NotFound(c *gin.Context){
	c.JSON(http.StatusNotFound,gin.H{
		"status":404,
		"error":"404,page not exissts"
	})
}

func AddStruct(Name string,Passwd string){
	var user User
	user.UserName=Name
	user.PassWord=Passwd
	user.Id=len(Slice)+1
	slicce=append(Slice,user)
}
