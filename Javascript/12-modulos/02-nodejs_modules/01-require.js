// En Node.js, para usar modulos dentro de la carpeta 'node_modules' es necesario utilizar
// la funcion 'require'

var axios = require('axios');

// La gran mayoria de desarrolladores recomienda utilizar este metodo para importar librerias
// de Node.js

console.log(axios);
// [Function: wrap] {
//     constructor: [Function: wrap],
//     request: [Function: wrap],
//     getUri: [Function: wrap],
//     delete: [Function: wrap],
//     get: [Function: wrap],
//     head: [Function: wrap],
//     options: [Function: wrap],
//     post: [Function: wrap],
//     postForm: [Function: wrap],
//     put: [Function: wrap],
//     putForm: [Function: wrap],
//     patch: [Function: wrap],
//     patchForm: [Function: wrap],
//     defaults: {
//       transitional: {
//         silentJSONParsing: true,
//         forcedJSONParsing: true,
//         clarifyTimeoutError: false
//       },
//       adapter: [Function: httpAdapter],
//       transformRequest: [ [Function: transformRequest] ],
//       transformResponse: [ [Function: transformResponse] ],
//       timeout: 0,
//       xsrfCookieName: 'XSRF-TOKEN',
//       xsrfHeaderName: 'X-XSRF-TOKEN',
//       maxContentLength: -1,
//       maxBodyLength: -1,
//       env: { FormData: [Function], Blob: null },
//       validateStatus: [Function: validateStatus],
//       headers: {
//         common: [Object],
//         delete: {},
//         get: {},
//         head: {},
//         post: [Object],
//         put: [Object],
//         patch: [Object]
//       }
//     },
//     interceptors: {
//       request: InterceptorManager { handlers: [] },
//       response: InterceptorManager { handlers: [] }
//     },
//     create: [Function: create],
//     Axios: [class Axios],
//     CanceledError: [Function: CanceledError],
//     CancelToken: [class CancelToken],
//     isCancel: [Function: isCancel],
//     VERSION: '1.1.3',
//     toFormData: [Function: toFormData],
//     AxiosError: [Function: AxiosError] { from: [Function (anonymous)] },
//     Cancel: [Function: CanceledError],
//     all: [Function: all],
//     spread: [Function: spread],
//     isAxiosError: [Function: isAxiosError],
//     formToJSON: [Function (anonymous)]
//   }
