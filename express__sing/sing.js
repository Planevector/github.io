var express=require('express');
var singController=require('./controllers/Singcontrollers');
var app=express();
app.set('view engine','ejs');

app.get('/',function(req,res){
res.send('if you want access the form please enter /sing');
});
app.get('/sing',function(req,res){
    res.render('sing');
    singController(app);
        });



app.listen(3000);
console.log('port to 3000');