package gin_api

import (
    "Sing/data"
    "Sing/func_judge"
    "net/http"
    "github.com/gin-gonic/gin"
)
func Register(c *gin.Context){
	UserName :=c.Request.FormValue("Name")
	PassWord :=c.Request.FormValue("Passwd")

	Bool :=func_judge.IsExist(UserName)
	if Bool{
		data.State["state"]=1
		data.State["text"]="user already exists"	
	}else{
		AddStruct(UserName,PassWord)
		data.State["state"]=1
		data.State["text"]="login was successful"
	}
	
	c.String(200,"%v",data.State)

}

func Login(c *gin.Context){
	UserName :=c.Request.FormValue("Name")
	PassWord :=c.Request.FormValue("Passwd")

	Bool :=func_judge.IsExist(UserName)
	if Bool{
		Bool_Pwd :=func_judge.IsRight(UserName,PassWord)
		if Bool_Pwd{
			data.State["state"]="1"
			data.State["text"]="sing was successful"
		}else{
			data.State["state"]=0
			data.State["text"]="Password Error"
		}
	}else{
		data.State["state"]=2
		data.State["text"]="login fail user not registered"
	}
	c.String(200,"%v",data.State)

}

func NotFound(c *gin.Context){
	c.JSON(http.StatusNotFound,gin.H{
		"status":404,
		"error":"404,page not exissts",
	})
}

func AddStruct(Name string,Passwd string){
	var user data.User
	user.UserName=Name
	user.PassWord=Passwd
	user.Id=len(data.Slice)+1
	data.Slice=append(data.Slice,user)
}
