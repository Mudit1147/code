const http=require('http');
const server=http.createServer((req,res)=>{
    
    res.writeHead(200,{"content-type":"text/plain",server:"Node.js"});
    
    res.end("Hello World");
});
const PORT=3008;
server.listen(PORT,()=>{
    console.log(`Server is running on port http://localhost:${PORT}`);
});