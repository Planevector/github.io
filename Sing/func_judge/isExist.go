package func_judge
import (
     ."Sing/data"
)

func IsExist(user string)bool{
	if len(Slice)==0{
		return false
	}else{
		for _,v :=range Slice{
			if v.UserName==user{
				return true
			}
		}
	}
return false
}

func IsRight(User string,Passwd string)bool{
	for _,v :=range Slice{
if v.UserName==User{
	return v.PassWord==Passwd
}
	}
	return false
}