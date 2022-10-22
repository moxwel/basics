function resolveAfter2Seconds() {
    return new Promise(resolve => {
        setTimeout(() => {
            resolve('resultado');
        }, 2000);
    });
}

async function asyncCall() {
    console.log('calling');

    const result = await resolveAfter2Seconds();

    result
    return result
    // expected output: "resolved"
}



asyncCall().then((res)=>{console.log(res)})
