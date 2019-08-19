package func_judge
import (
    . "https/data"
)

func IsExist(user string)bool{
	if len(Slice)==0{
		return false
	}else{
		for _,V :=range Slice{
			if v.UserName=user{
				return true
			}
		}
	}
return false
}

func IsRight(User string,Passwd string)bool{
	for _,v :=range Slice{
if v.UserName=user{
	return v.PassWord
}
	}
	return
}