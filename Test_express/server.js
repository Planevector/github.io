var express=require('express');
var app=express();
var bodyParser=require('body-parser');
var jsonParser=bodyParser.json();
var urlencodedParser=bodyParser.urlencoded({extended:false});
var fs=require('fs');
var multer=require('multer');
var createFolder=function(folder){
    try{
        fs.accessSync(folder);
    }catch(e){
        fs.mkdirSync(folder);
    }
};
var uploadFolder='./upload';
createFolder(uploadFolder);
var storage = multer.diskStorage({
    destination: function (req, file, cb) {
      cb(null, uploadFolder);
    },
    filename: function (req, file, cb) {
      cb(null, file.originalname);
    }
  })
   
  var upload = multer({ storage: storage })
app.set('view engine','ejs');
app.use(express.static('public'));

var indexRouter=require('./routes/index');
var usersRouter=require('./routes/users');


//1

/**
 app.get('/',function(req,res){
    res.send('123');
});
 */
 
//2
/*
app.get('/',function(req,res){
   var response={
       name:"sad"
   };
    res.send(response);
});*/
//3
/*
app.get('/',function(req,res){
    var response=req.ip;
     res.send(response);
    });
     */
//4
/**
 app.get('/',function(req,res){
    var response=req.method;
     res.send(response);
    });
     */
//5
/**
 * app.get('/file/:id',function(req,res){
    console.dir(req.params);
     res.send('port to 3000:'+req.params.id);
    });
 */
//6
/**
 app.get('/file/:id/user/:name',function(req,res){
    console.dir(req.params);
     res.send('port to 3000:'+req.params.id);
    });
 */
//7
/**
 * app.get('/ab?cd',function(req,res){
     res.send('abcd');
    });
 */

//8
/**
 * app.get('/',function(req,res){
    console.dir(req.query);
     res.send('page:'+req.query.find);
    });
 */
//8{post请求}
/**
 * app.post('/',urlencodedParser,function(req,res){
    console.dir(req.body);
    res.send(req.body.name );
});
 */

//9
/**
 * app.post('/upload',jsonParser,function(req,res){
    console.dir(req.body);
    res.send(req.body.name );
});
 */

//10文件上传
/**
 * app.get('/form',jsonParser,function(req,res){
  var form=fs.readFileSync('./form.html',{encoding:"utf8"});
  res.send(form);
});
 */
//10.1
/**
 * app.post('/upload',upload.single('logo'),function(req,res){
    console.dir(req.file);
    res.send('ok');
 });
 */
 //10.2
 /**
  * app.post('/upload',function(req,res){
     var person=req.params.name;
    res.sendFile(__dirname+'/form.html');
 }); 
  */
//11模板引擎
/**
 * app.get('/form/:name',function(req,res){
    var person=req.params.name;
   res.render('form',{person:person});
}); 
 */
//11.2
/**
 * app.get('/form/:name',function(req,res){
    var  data={age:29,job:"student",hobbit:['sad','asd']};
   res.render('form',{data:data});
}); 
 */
//11.3模板共用
/**
 * app.get('/about',function(req,res){

   res.render('about');
}); 
 */
//12中间间
// app.use(function(req,res,next){
//     console.log('sadsad');
//     next();
// });
// app.use(function(req,res,next){
//     console.log('sadsad');
//     res.send('oka');
// });

// app.get('users',function(req,res,next){
// res.send('users');
// });
// app.get('/',function(req,res,next){
//     res.send('root');
//     });

//13
app.use('/',indexRouter);
app.use('/users',usersRouter);


app.listen(3000);
console.log('listen to port');