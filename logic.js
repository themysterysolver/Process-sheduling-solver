function display(result){
    const nrow=result[0].length;
    const ncol=result.length;
    let tableBody=document.getElementById("tableBody");
    for(let i=0;i<nrow;i++){
        let row=document.createElement('tr');
        for(let j=0;j<ncol;j++){
            let col=document.createElement('td');
            col.innerHTML=result[j][i];
            row.appendChild(col)
        }
        tableBody.appendChild(row);
    }
}
function turn_around_time(ct,at){
    const n=ct.length;
    let tat=new Array(n);
    for(let i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
    }
    console.log(tat);
    return tat;
}
function waiting_time(tat,bt){
    const n=tat.length
    let wt=new Array(n);
    for(let i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
    }
    console.log(wt);
    return wt;
}
function fcfs(at,bt){
    let array_at=at;
    let array_bt=bt;
    const n=array_at.length;
    let completion_time=new Array(n);

    //console.log(completion_time);
    let indices = Array.from({ length: at.length },(_,i) =>i);
    indices.sort((a,b)=>array_at[a]-array_at[b]);
    array_at=indices.map(i=>array_at[i]);
    array_bt=indices.map(i=>array_bt[i]);

    completion_time[0]=array_at[0]+array_bt[0];
    for(let i=1;i<n;i++){
        completion_time[i]=completion_time[i-1]+array_bt[i];
    }
    let tat=turn_around_time(completion_time,array_at);
    let wt=waiting_time(tat,array_bt);
    console.log('completion time:'+completion_time);
    console.log('tat time:'+tat);
    console.log('waiting time:'+wt);
    return [indices,array_at,array_bt,completion_time,tat,wt]
}
function sjf(at,bt){
    let array_at=at;
    let array_bt=bt;
    const n=array_at.length;
    let completion_time=new Array(n).fill(0);
    let indices = Array.from({ length: at.length },(_,i) =>i);
    indices.sort((a,b)=>array_at[a]-array_at[b]);
    array_at=indices.map(i=>array_at[i]);
    array_bt=indices.map(i=>array_bt[i]);
    let completed=0
    let current_time=0
    let isCompleted=new Array(n).fill(0);
    for(let i=0;i<n;i++){
        isCompleted[i]=0;
    }
    while(completed!=n){
        let min=-1;
        for(let i=0;i<n;i++){
            if(isCompleted[i]==0 && array_at[i]<=current_time){
                if(min==-1||array_bt[min]>array_bt[i]){
                    min=i;
                }
            }
        }
        if(min!=-1){
            current_time += array_bt[min];
            completion_time[min] = current_time;
            isCompleted[min]=1;
            completed++;
        }
        else{
            current_time++;
        }
    }
    let tat=turn_around_time(completion_time,array_at);
    let wt=waiting_time(tat,array_bt);
    console.log('completion time:'+completion_time);
    console.log('tat time:'+tat);
    console.log('waiting time:'+wt);
    return [indices,array_at,array_bt,completion_time,tat,wt]
}
function calculate(){
    let choice=document.getElementById("myOption").value;
    let array_AT=document.getElementById("AT").value.split(' ').filter(item=>item!='').map(Number)
    let array_BT=document.getElementById("BT").value.split(' ').filter(item=>item!='').map(Number)
    document.getElementById("tableOutput").style.display='block';
    tableBody.innerHTML='';
    console.log(choice);
    let result;
    switch (choice) {
        case "FCFS":
                result=fcfs(array_AT,array_BT);//const result=fcfs(array_AT,array_BT);fcfs([2,5,0,0,7],[7,3,2,10,8]);
                console.log(result)
                display(result)
            break;
        case "SJF":
            result=sjf(array_AT,array_BT)
            console.log(result)
            display(result)
            break;
        case "SRTF":
            
            break;
        case "PPS":
            
            break;
        case "NPPS":
            
            break;
        case "RR":
            
            break;
        default:
            
            break;
    }

}