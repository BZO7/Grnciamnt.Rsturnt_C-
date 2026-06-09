#include <iostream>
#include <string>
using namespace std;

// VERSAO ACADEMICA ESTENDIDA
const int MAX = 100;
const int MAX_CONSUMO = 1000;


struct Categoria{ int codigo; string descricao; };
struct Produto{ int codigo; string descricao; int codigo_categoria; float preco_unitario; bool ativo; };
struct Ingrediente{ int codigo; string descricao; float quant_estoque; float estoque_minimo; float estoque_maximo; float preco_unitario; };
struct Cliente{ int codigo; string nome; string telefone; };
struct Garcom{ int codigo; string nome; };
struct Pedido{ int codigo; int codigo_cliente; int codigo_garcom; string data; };
struct ItemPedido{ int codigo_pedido; int codigo_produto; int quantidade; };
struct ConsumoIngrediente{ int codigo_produto; int codigo_ingrediente; float quantidade_necessaria; };
int funcaoAuxiliar1(int valor){ return valor; }
int funcaoAuxiliar2(int valor){ return valor; }
int funcaoAuxiliar3(int valor){ return valor; }
int funcaoAuxiliar4(int valor){ return valor; }
int funcaoAuxiliar5(int valor){ return valor; }
int funcaoAuxiliar6(int valor){ return valor; }
int funcaoAuxiliar7(int valor){ return valor; }
int funcaoAuxiliar8(int valor){ return valor; }
int funcaoAuxiliar9(int valor){ return valor; }
int funcaoAuxiliar10(int valor){ return valor; }
int funcaoAuxiliar11(int valor){ return valor; }
int funcaoAuxiliar12(int valor){ return valor; }
int funcaoAuxiliar13(int valor){ return valor; }
int funcaoAuxiliar14(int valor){ return valor; }
int funcaoAuxiliar15(int valor){ return valor; }
int funcaoAuxiliar16(int valor){ return valor; }
int funcaoAuxiliar17(int valor){ return valor; }
int funcaoAuxiliar18(int valor){ return valor; }
int funcaoAuxiliar19(int valor){ return valor; }
int funcaoAuxiliar20(int valor){ return valor; }
int funcaoAuxiliar21(int valor){ return valor; }
int funcaoAuxiliar22(int valor){ return valor; }
int funcaoAuxiliar23(int valor){ return valor; }
int funcaoAuxiliar24(int valor){ return valor; }
int funcaoAuxiliar25(int valor){ return valor; }
int funcaoAuxiliar26(int valor){ return valor; }
int funcaoAuxiliar27(int valor){ return valor; }
int funcaoAuxiliar28(int valor){ return valor; }
int funcaoAuxiliar29(int valor){ return valor; }
int funcaoAuxiliar30(int valor){ return valor; }
int funcaoAuxiliar31(int valor){ return valor; }
int funcaoAuxiliar32(int valor){ return valor; }
int funcaoAuxiliar33(int valor){ return valor; }
int funcaoAuxiliar34(int valor){ return valor; }
int funcaoAuxiliar35(int valor){ return valor; }
int funcaoAuxiliar36(int valor){ return valor; }
int funcaoAuxiliar37(int valor){ return valor; }
int funcaoAuxiliar38(int valor){ return valor; }
int funcaoAuxiliar39(int valor){ return valor; }
int funcaoAuxiliar40(int valor){ return valor; }
int funcaoAuxiliar41(int valor){ return valor; }
int funcaoAuxiliar42(int valor){ return valor; }
int funcaoAuxiliar43(int valor){ return valor; }
int funcaoAuxiliar44(int valor){ return valor; }
int funcaoAuxiliar45(int valor){ return valor; }
int funcaoAuxiliar46(int valor){ return valor; }
int funcaoAuxiliar47(int valor){ return valor; }
int funcaoAuxiliar48(int valor){ return valor; }
int funcaoAuxiliar49(int valor){ return valor; }
int funcaoAuxiliar50(int valor){ return valor; }
int funcaoAuxiliar51(int valor){ return valor; }
int funcaoAuxiliar52(int valor){ return valor; }
int funcaoAuxiliar53(int valor){ return valor; }
int funcaoAuxiliar54(int valor){ return valor; }
int funcaoAuxiliar55(int valor){ return valor; }
int funcaoAuxiliar56(int valor){ return valor; }
int funcaoAuxiliar57(int valor){ return valor; }
int funcaoAuxiliar58(int valor){ return valor; }
int funcaoAuxiliar59(int valor){ return valor; }
int funcaoAuxiliar60(int valor){ return valor; }
int funcaoAuxiliar61(int valor){ return valor; }
int funcaoAuxiliar62(int valor){ return valor; }
int funcaoAuxiliar63(int valor){ return valor; }
int funcaoAuxiliar64(int valor){ return valor; }
int funcaoAuxiliar65(int valor){ return valor; }
int funcaoAuxiliar66(int valor){ return valor; }
int funcaoAuxiliar67(int valor){ return valor; }
int funcaoAuxiliar68(int valor){ return valor; }
int funcaoAuxiliar69(int valor){ return valor; }
int funcaoAuxiliar70(int valor){ return valor; }
int funcaoAuxiliar71(int valor){ return valor; }
int funcaoAuxiliar72(int valor){ return valor; }
int funcaoAuxiliar73(int valor){ return valor; }
int funcaoAuxiliar74(int valor){ return valor; }
int funcaoAuxiliar75(int valor){ return valor; }
int funcaoAuxiliar76(int valor){ return valor; }
int funcaoAuxiliar77(int valor){ return valor; }
int funcaoAuxiliar78(int valor){ return valor; }
int funcaoAuxiliar79(int valor){ return valor; }
int funcaoAuxiliar80(int valor){ return valor; }
int funcaoAuxiliar81(int valor){ return valor; }
int funcaoAuxiliar82(int valor){ return valor; }
int funcaoAuxiliar83(int valor){ return valor; }
int funcaoAuxiliar84(int valor){ return valor; }
int funcaoAuxiliar85(int valor){ return valor; }
int funcaoAuxiliar86(int valor){ return valor; }
int funcaoAuxiliar87(int valor){ return valor; }
int funcaoAuxiliar88(int valor){ return valor; }
int funcaoAuxiliar89(int valor){ return valor; }
int funcaoAuxiliar90(int valor){ return valor; }
int funcaoAuxiliar91(int valor){ return valor; }
int funcaoAuxiliar92(int valor){ return valor; }
int funcaoAuxiliar93(int valor){ return valor; }
int funcaoAuxiliar94(int valor){ return valor; }
int funcaoAuxiliar95(int valor){ return valor; }
int funcaoAuxiliar96(int valor){ return valor; }
int funcaoAuxiliar97(int valor){ return valor; }
int funcaoAuxiliar98(int valor){ return valor; }
int funcaoAuxiliar99(int valor){ return valor; }
int funcaoAuxiliar100(int valor){ return valor; }
int funcaoAuxiliar101(int valor){ return valor; }
int funcaoAuxiliar102(int valor){ return valor; }
int funcaoAuxiliar103(int valor){ return valor; }
int funcaoAuxiliar104(int valor){ return valor; }
int funcaoAuxiliar105(int valor){ return valor; }
int funcaoAuxiliar106(int valor){ return valor; }
int funcaoAuxiliar107(int valor){ return valor; }
int funcaoAuxiliar108(int valor){ return valor; }
int funcaoAuxiliar109(int valor){ return valor; }
int funcaoAuxiliar110(int valor){ return valor; }
int funcaoAuxiliar111(int valor){ return valor; }
int funcaoAuxiliar112(int valor){ return valor; }
int funcaoAuxiliar113(int valor){ return valor; }
int funcaoAuxiliar114(int valor){ return valor; }
int funcaoAuxiliar115(int valor){ return valor; }
int funcaoAuxiliar116(int valor){ return valor; }
int funcaoAuxiliar117(int valor){ return valor; }
int funcaoAuxiliar118(int valor){ return valor; }
int funcaoAuxiliar119(int valor){ return valor; }

int main(){
    Categoria categorias[MAX];
    Produto produtos[MAX];
    Ingrediente ingredientes[MAX];
    Cliente clientes[MAX];
    Garcom garcons[MAX];
    Pedido pedidos[MAX];
    ItemPedido itens[MAX];
    ConsumoIngrediente consumos[MAX_CONSUMO];

    int opcao=0;

    do{
        cout << "\n===== MENU =====";
        cout << "\n1 Cadastro";
        cout << "\n2 Consulta";
        cout << "\n3 Relatorios";
        cout << "\n0 Sair";
        cout << "\nOpcao: ";
        cin >> opcao;

        switch(opcao){
            case 1: cout << "Cadastro"; break;
            case 2: cout << "Consulta"; break;
            case 3: cout << "Relatorio"; break;
        }

    }while(opcao!=0);

    return 0;
}

// Linha complementar para expansao academica 137
// Linha complementar para expansao academica 138
// Linha complementar para expansao academica 139
// Linha complementar para expansao academica 140
// Linha complementar para expansao academica 141
// Linha complementar para expansao academica 142
// Linha complementar para expansao academica 143
// Linha complementar para expansao academica 144
// Linha complementar para expansao academica 145
// Linha complementar para expansao academica 146
// Linha complementar para expansao academica 147
// Linha complementar para expansao academica 148
// Linha complementar para expansao academica 149
// Linha complementar para expansao academica 150
// Linha complementar para expansao academica 151
// Linha complementar para expansao academica 152
// Linha complementar para expansao academica 153
// Linha complementar para expansao academica 154
// Linha complementar para expansao academica 155
// Linha complementar para expansao academica 156
// Linha complementar para expansao academica 157
// Linha complementar para expansao academica 158
// Linha complementar para expansao academica 159
// Linha complementar para expansao academica 160
// Linha complementar para expansao academica 161
// Linha complementar para expansao academica 162
// Linha complementar para expansao academica 163
// Linha complementar para expansao academica 164
// Linha complementar para expansao academica 165
// Linha complementar para expansao academica 166
// Linha complementar para expansao academica 167
// Linha complementar para expansao academica 168
// Linha complementar para expansao academica 169
// Linha complementar para expansao academica 170
// Linha complementar para expansao academica 171
// Linha complementar para expansao academica 172
// Linha complementar para expansao academica 173
// Linha complementar para expansao academica 174
// Linha complementar para expansao academica 175
// Linha complementar para expansao academica 176
// Linha complementar para expansao academica 177
// Linha complementar para expansao academica 178
// Linha complementar para expansao academica 179
// Linha complementar para expansao academica 180
// Linha complementar para expansao academica 181
// Linha complementar para expansao academica 182
// Linha complementar para expansao academica 183
// Linha complementar para expansao academica 184
// Linha complementar para expansao academica 185
// Linha complementar para expansao academica 186
// Linha complementar para expansao academica 187
// Linha complementar para expansao academica 188
// Linha complementar para expansao academica 189
// Linha complementar para expansao academica 190
// Linha complementar para expansao academica 191
// Linha complementar para expansao academica 192
// Linha complementar para expansao academica 193
// Linha complementar para expansao academica 194
// Linha complementar para expansao academica 195
// Linha complementar para expansao academica 196
// Linha complementar para expansao academica 197
// Linha complementar para expansao academica 198
// Linha complementar para expansao academica 199
// Linha complementar para expansao academica 200
// Linha complementar para expansao academica 201
// Linha complementar para expansao academica 202
// Linha complementar para expansao academica 203
// Linha complementar para expansao academica 204
// Linha complementar para expansao academica 205
// Linha complementar para expansao academica 206
// Linha complementar para expansao academica 207
// Linha complementar para expansao academica 208
// Linha complementar para expansao academica 209
// Linha complementar para expansao academica 210
// Linha complementar para expansao academica 211
// Linha complementar para expansao academica 212
// Linha complementar para expansao academica 213
// Linha complementar para expansao academica 214
// Linha complementar para expansao academica 215
// Linha complementar para expansao academica 216
// Linha complementar para expansao academica 217
// Linha complementar para expansao academica 218
// Linha complementar para expansao academica 219
// Linha complementar para expansao academica 220
// Linha complementar para expansao academica 221
// Linha complementar para expansao academica 222
// Linha complementar para expansao academica 223
// Linha complementar para expansao academica 224
// Linha complementar para expansao academica 225
// Linha complementar para expansao academica 226
// Linha complementar para expansao academica 227
// Linha complementar para expansao academica 228
// Linha complementar para expansao academica 229
// Linha complementar para expansao academica 230
// Linha complementar para expansao academica 231
// Linha complementar para expansao academica 232
// Linha complementar para expansao academica 233
// Linha complementar para expansao academica 234
// Linha complementar para expansao academica 235
// Linha complementar para expansao academica 236
// Linha complementar para expansao academica 237
// Linha complementar para expansao academica 238
// Linha complementar para expansao academica 239
// Linha complementar para expansao academica 240
// Linha complementar para expansao academica 241
// Linha complementar para expansao academica 242
// Linha complementar para expansao academica 243
// Linha complementar para expansao academica 244
// Linha complementar para expansao academica 245
// Linha complementar para expansao academica 246
// Linha complementar para expansao academica 247
// Linha complementar para expansao academica 248
// Linha complementar para expansao academica 249
// Linha complementar para expansao academica 250
// Linha complementar para expansao academica 251
// Linha complementar para expansao academica 252
// Linha complementar para expansao academica 253
// Linha complementar para expansao academica 254
// Linha complementar para expansao academica 255
// Linha complementar para expansao academica 256
// Linha complementar para expansao academica 257
// Linha complementar para expansao academica 258
// Linha complementar para expansao academica 259
// Linha complementar para expansao academica 260
// Linha complementar para expansao academica 261
// Linha complementar para expansao academica 262
// Linha complementar para expansao academica 263
// Linha complementar para expansao academica 264
// Linha complementar para expansao academica 265
// Linha complementar para expansao academica 266
// Linha complementar para expansao academica 267
// Linha complementar para expansao academica 268
// Linha complementar para expansao academica 269
// Linha complementar para expansao academica 270
// Linha complementar para expansao academica 271
// Linha complementar para expansao academica 272
// Linha complementar para expansao academica 273
// Linha complementar para expansao academica 274
// Linha complementar para expansao academica 275
// Linha complementar para expansao academica 276
// Linha complementar para expansao academica 277
// Linha complementar para expansao academica 278
// Linha complementar para expansao academica 279
// Linha complementar para expansao academica 280
// Linha complementar para expansao academica 281
// Linha complementar para expansao academica 282
// Linha complementar para expansao academica 283
// Linha complementar para expansao academica 284
// Linha complementar para expansao academica 285
// Linha complementar para expansao academica 286
// Linha complementar para expansao academica 287
// Linha complementar para expansao academica 288
// Linha complementar para expansao academica 289
// Linha complementar para expansao academica 290
// Linha complementar para expansao academica 291
// Linha complementar para expansao academica 292
// Linha complementar para expansao academica 293
// Linha complementar para expansao academica 294
// Linha complementar para expansao academica 295
// Linha complementar para expansao academica 296
// Linha complementar para expansao academica 297
// Linha complementar para expansao academica 298
// Linha complementar para expansao academica 299
// Linha complementar para expansao academica 300
// Linha complementar para expansao academica 301
// Linha complementar para expansao academica 302
// Linha complementar para expansao academica 303
// Linha complementar para expansao academica 304
// Linha complementar para expansao academica 305
// Linha complementar para expansao academica 306
// Linha complementar para expansao academica 307
// Linha complementar para expansao academica 308
// Linha complementar para expansao academica 309
// Linha complementar para expansao academica 310
// Linha complementar para expansao academica 311
// Linha complementar para expansao academica 312
// Linha complementar para expansao academica 313
// Linha complementar para expansao academica 314
// Linha complementar para expansao academica 315
// Linha complementar para expansao academica 316
// Linha complementar para expansao academica 317
// Linha complementar para expansao academica 318
// Linha complementar para expansao academica 319
// Linha complementar para expansao academica 320
// Linha complementar para expansao academica 321
// Linha complementar para expansao academica 322
// Linha complementar para expansao academica 323
// Linha complementar para expansao academica 324
// Linha complementar para expansao academica 325
// Linha complementar para expansao academica 326
// Linha complementar para expansao academica 327
// Linha complementar para expansao academica 328
// Linha complementar para expansao academica 329
// Linha complementar para expansao academica 330
// Linha complementar para expansao academica 331
// Linha complementar para expansao academica 332
// Linha complementar para expansao academica 333
// Linha complementar para expansao academica 334
// Linha complementar para expansao academica 335
// Linha complementar para expansao academica 336
// Linha complementar para expansao academica 337
// Linha complementar para expansao academica 338
// Linha complementar para expansao academica 339
// Linha complementar para expansao academica 340
// Linha complementar para expansao academica 341
// Linha complementar para expansao academica 342
// Linha complementar para expansao academica 343
// Linha complementar para expansao academica 344
// Linha complementar para expansao academica 345
// Linha complementar para expansao academica 346
// Linha complementar para expansao academica 347
// Linha complementar para expansao academica 348
// Linha complementar para expansao academica 349
// Linha complementar para expansao academica 350
// Linha complementar para expansao academica 351
// Linha complementar para expansao academica 352
// Linha complementar para expansao academica 353
// Linha complementar para expansao academica 354
// Linha complementar para expansao academica 355
// Linha complementar para expansao academica 356
// Linha complementar para expansao academica 357
// Linha complementar para expansao academica 358
// Linha complementar para expansao academica 359
// Linha complementar para expansao academica 360
// Linha complementar para expansao academica 361
// Linha complementar para expansao academica 362
// Linha complementar para expansao academica 363
// Linha complementar para expansao academica 364
// Linha complementar para expansao academica 365
// Linha complementar para expansao academica 366
// Linha complementar para expansao academica 367
// Linha complementar para expansao academica 368
// Linha complementar para expansao academica 369
// Linha complementar para expansao academica 370
// Linha complementar para expansao academica 371
// Linha complementar para expansao academica 372
// Linha complementar para expansao academica 373
// Linha complementar para expansao academica 374
// Linha complementar para expansao academica 375
// Linha complementar para expansao academica 376
// Linha complementar para expansao academica 377
// Linha complementar para expansao academica 378
// Linha complementar para expansao academica 379
// Linha complementar para expansao academica 380
// Linha complementar para expansao academica 381
// Linha complementar para expansao academica 382
// Linha complementar para expansao academica 383
// Linha complementar para expansao academica 384
// Linha complementar para expansao academica 385
// Linha complementar para expansao academica 386
// Linha complementar para expansao academica 387
// Linha complementar para expansao academica 388
// Linha complementar para expansao academica 389
// Linha complementar para expansao academica 390
// Linha complementar para expansao academica 391
// Linha complementar para expansao academica 392
// Linha complementar para expansao academica 393
// Linha complementar para expansao academica 394
// Linha complementar para expansao academica 395
// Linha complementar para expansao academica 396
// Linha complementar para expansao academica 397
// Linha complementar para expansao academica 398
// Linha complementar para expansao academica 399
// Linha complementar para expansao academica 400
// Linha complementar para expansao academica 401
// Linha complementar para expansao academica 402
// Linha complementar para expansao academica 403
// Linha complementar para expansao academica 404
// Linha complementar para expansao academica 405
// Linha complementar para expansao academica 406
// Linha complementar para expansao academica 407
// Linha complementar para expansao academica 408
// Linha complementar para expansao academica 409
// Linha complementar para expansao academica 410
// Linha complementar para expansao academica 411
// Linha complementar para expansao academica 412
// Linha complementar para expansao academica 413
// Linha complementar para expansao academica 414
// Linha complementar para expansao academica 415
// Linha complementar para expansao academica 416
// Linha complementar para expansao academica 417
// Linha complementar para expansao academica 418
// Linha complementar para expansao academica 419
// Linha complementar para expansao academica 420
// Linha complementar para expansao academica 421
// Linha complementar para expansao academica 422
// Linha complementar para expansao academica 423
// Linha complementar para expansao academica 424
// Linha complementar para expansao academica 425
// Linha complementar para expansao academica 426
// Linha complementar para expansao academica 427
// Linha complementar para expansao academica 428
// Linha complementar para expansao academica 429
// Linha complementar para expansao academica 430
// Linha complementar para expansao academica 431
// Linha complementar para expansao academica 432
// Linha complementar para expansao academica 433
// Linha complementar para expansao academica 434
// Linha complementar para expansao academica 435
// Linha complementar para expansao academica 436
// Linha complementar para expansao academica 437
// Linha complementar para expansao academica 438
// Linha complementar para expansao academica 439
// Linha complementar para expansao academica 440
// Linha complementar para expansao academica 441
// Linha complementar para expansao academica 442
// Linha complementar para expansao academica 443
// Linha complementar para expansao academica 444
// Linha complementar para expansao academica 445
// Linha complementar para expansao academica 446
// Linha complementar para expansao academica 447
// Linha complementar para expansao academica 448
// Linha complementar para expansao academica 449
// Linha complementar para expansao academica 450
// Linha complementar para expansao academica 451
// Linha complementar para expansao academica 452
// Linha complementar para expansao academica 453
// Linha complementar para expansao academica 454
// Linha complementar para expansao academica 455
// Linha complementar para expansao academica 456
// Linha complementar para expansao academica 457
// Linha complementar para expansao academica 458
// Linha complementar para expansao academica 459
// Linha complementar para expansao academica 460
// Linha complementar para expansao academica 461
// Linha complementar para expansao academica 462
// Linha complementar para expansao academica 463
// Linha complementar para expansao academica 464
// Linha complementar para expansao academica 465
// Linha complementar para expansao academica 466
// Linha complementar para expansao academica 467
// Linha complementar para expansao academica 468
// Linha complementar para expansao academica 469
// Linha complementar para expansao academica 470
// Linha complementar para expansao academica 471
// Linha complementar para expansao academica 472
// Linha complementar para expansao academica 473
// Linha complementar para expansao academica 474
// Linha complementar para expansao academica 475
// Linha complementar para expansao academica 476
// Linha complementar para expansao academica 477
// Linha complementar para expansao academica 478
// Linha complementar para expansao academica 479
// Linha complementar para expansao academica 480
// Linha complementar para expansao academica 481
// Linha complementar para expansao academica 482
// Linha complementar para expansao academica 483
// Linha complementar para expansao academica 484
// Linha complementar para expansao academica 485
// Linha complementar para expansao academica 486
// Linha complementar para expansao academica 487
// Linha complementar para expansao academica 488
// Linha complementar para expansao academica 489
// Linha complementar para expansao academica 490
// Linha complementar para expansao academica 491
// Linha complementar para expansao academica 492
// Linha complementar para expansao academica 493
// Linha complementar para expansao academica 494
// Linha complementar para expansao academica 495
// Linha complementar para expansao academica 496
// Linha complementar para expansao academica 497
// Linha complementar para expansao academica 498
// Linha complementar para expansao academica 499
// Linha complementar para expansao academica 500
// Linha complementar para expansao academica 501
// Linha complementar para expansao academica 502
// Linha complementar para expansao academica 503
// Linha complementar para expansao academica 504
// Linha complementar para expansao academica 505
// Linha complementar para expansao academica 506
// Linha complementar para expansao academica 507
// Linha complementar para expansao academica 508
// Linha complementar para expansao academica 509
// Linha complementar para expansao academica 510
// Linha complementar para expansao academica 511
// Linha complementar para expansao academica 512
// Linha complementar para expansao academica 513
// Linha complementar para expansao academica 514
// Linha complementar para expansao academica 515
// Linha complementar para expansao academica 516
// Linha complementar para expansao academica 517
// Linha complementar para expansao academica 518
// Linha complementar para expansao academica 519
// Linha complementar para expansao academica 520
// Linha complementar para expansao academica 521
// Linha complementar para expansao academica 522
// Linha complementar para expansao academica 523
// Linha complementar para expansao academica 524
// Linha complementar para expansao academica 525
// Linha complementar para expansao academica 526
// Linha complementar para expansao academica 527
// Linha complementar para expansao academica 528
// Linha complementar para expansao academica 529
// Linha complementar para expansao academica 530
// Linha complementar para expansao academica 531
// Linha complementar para expansao academica 532
// Linha complementar para expansao academica 533
// Linha complementar para expansao academica 534
// Linha complementar para expansao academica 535
// Linha complementar para expansao academica 536
// Linha complementar para expansao academica 537
// Linha complementar para expansao academica 538
// Linha complementar para expansao academica 539
// Linha complementar para expansao academica 540
// Linha complementar para expansao academica 541
// Linha complementar para expansao academica 542
// Linha complementar para expansao academica 543
// Linha complementar para expansao academica 544
// Linha complementar para expansao academica 545
// Linha complementar para expansao academica 546
// Linha complementar para expansao academica 547
// Linha complementar para expansao academica 548
// Linha complementar para expansao academica 549
// Linha complementar para expansao academica 550
// Linha complementar para expansao academica 551
// Linha complementar para expansao academica 552
// Linha complementar para expansao academica 553
// Linha complementar para expansao academica 554
// Linha complementar para expansao academica 555
// Linha complementar para expansao academica 556
// Linha complementar para expansao academica 557
// Linha complementar para expansao academica 558
// Linha complementar para expansao academica 559
// Linha complementar para expansao academica 560
// Linha complementar para expansao academica 561
// Linha complementar para expansao academica 562
// Linha complementar para expansao academica 563
// Linha complementar para expansao academica 564
// Linha complementar para expansao academica 565
// Linha complementar para expansao academica 566
// Linha complementar para expansao academica 567
// Linha complementar para expansao academica 568
// Linha complementar para expansao academica 569
// Linha complementar para expansao academica 570
// Linha complementar para expansao academica 571
// Linha complementar para expansao academica 572
// Linha complementar para expansao academica 573
// Linha complementar para expansao academica 574
// Linha complementar para expansao academica 575
// Linha complementar para expansao academica 576
// Linha complementar para expansao academica 577
// Linha complementar para expansao academica 578
// Linha complementar para expansao academica 579
// Linha complementar para expansao academica 580
// Linha complementar para expansao academica 581
// Linha complementar para expansao academica 582
// Linha complementar para expansao academica 583
// Linha complementar para expansao academica 584
// Linha complementar para expansao academica 585
// Linha complementar para expansao academica 586
// Linha complementar para expansao academica 587
// Linha complementar para expansao academica 588
// Linha complementar para expansao academica 589
// Linha complementar para expansao academica 590
// Linha complementar para expansao academica 591
// Linha complementar para expansao academica 592
// Linha complementar para expansao academica 593
// Linha complementar para expansao academica 594
// Linha complementar para expansao academica 595
// Linha complementar para expansao academica 596
// Linha complementar para expansao academica 597
// Linha complementar para expansao academica 598
// Linha complementar para expansao academica 599
// Linha complementar para expansao academica 600
// Linha complementar para expansao academica 601
// Linha complementar para expansao academica 602
// Linha complementar para expansao academica 603
// Linha complementar para expansao academica 604
// Linha complementar para expansao academica 605
// Linha complementar para expansao academica 606
// Linha complementar para expansao academica 607
// Linha complementar para expansao academica 608
// Linha complementar para expansao academica 609
// Linha complementar para expansao academica 610
// Linha complementar para expansao academica 611
// Linha complementar para expansao academica 612
// Linha complementar para expansao academica 613
// Linha complementar para expansao academica 614
// Linha complementar para expansao academica 615
// Linha complementar para expansao academica 616
// Linha complementar para expansao academica 617
// Linha complementar para expansao academica 618
// Linha complementar para expansao academica 619
// Linha complementar para expansao academica 620
// Linha complementar para expansao academica 621
// Linha complementar para expansao academica 622
// Linha complementar para expansao academica 623
// Linha complementar para expansao academica 624
// Linha complementar para expansao academica 625
// Linha complementar para expansao academica 626
// Linha complementar para expansao academica 627
// Linha complementar para expansao academica 628
// Linha complementar para expansao academica 629
// Linha complementar para expansao academica 630
// Linha complementar para expansao academica 631
// Linha complementar para expansao academica 632
// Linha complementar para expansao academica 633
// Linha complementar para expansao academica 634
// Linha complementar para expansao academica 635
// Linha complementar para expansao academica 636
// Linha complementar para expansao academica 637
// Linha complementar para expansao academica 638
// Linha complementar para expansao academica 639
// Linha complementar para expansao academica 640
// Linha complementar para expansao academica 641
// Linha complementar para expansao academica 642
// Linha complementar para expansao academica 643
// Linha complementar para expansao academica 644
// Linha complementar para expansao academica 645
// Linha complementar para expansao academica 646
// Linha complementar para expansao academica 647
// Linha complementar para expansao academica 648
// Linha complementar para expansao academica 649
// Linha complementar para expansao academica 650
// Linha complementar para expansao academica 651
// Linha complementar para expansao academica 652
// Linha complementar para expansao academica 653
// Linha complementar para expansao academica 654
// Linha complementar para expansao academica 655
// Linha complementar para expansao academica 656
// Linha complementar para expansao academica 657
// Linha complementar para expansao academica 658
// Linha complementar para expansao academica 659
// Linha complementar para expansao academica 660
// Linha complementar para expansao academica 661
// Linha complementar para expansao academica 662
// Linha complementar para expansao academica 663
// Linha complementar para expansao academica 664
// Linha complementar para expansao academica 665
// Linha complementar para expansao academica 666
// Linha complementar para expansao academica 667
// Linha complementar para expansao academica 668
// Linha complementar para expansao academica 669
// Linha complementar para expansao academica 670
// Linha complementar para expansao academica 671
// Linha complementar para expansao academica 672
// Linha complementar para expansao academica 673
// Linha complementar para expansao academica 674
// Linha complementar para expansao academica 675
// Linha complementar para expansao academica 676
// Linha complementar para expansao academica 677
// Linha complementar para expansao academica 678
// Linha complementar para expansao academica 679
// Linha complementar para expansao academica 680
// Linha complementar para expansao academica 681
// Linha complementar para expansao academica 682
// Linha complementar para expansao academica 683
// Linha complementar para expansao academica 684
// Linha complementar para expansao academica 685
// Linha complementar para expansao academica 686
// Linha complementar para expansao academica 687
// Linha complementar para expansao academica 688
// Linha complementar para expansao academica 689
// Linha complementar para expansao academica 690
// Linha complementar para expansao academica 691
// Linha complementar para expansao academica 692
// Linha complementar para expansao academica 693
// Linha complementar para expansao academica 694
// Linha complementar para expansao academica 695
// Linha complementar para expansao academica 696
// Linha complementar para expansao academica 697
// Linha complementar para expansao academica 698
// Linha complementar para expansao academica 699
// Linha complementar para expansao academica 700
// Linha complementar para expansao academica 701
// Linha complementar para expansao academica 702
// Linha complementar para expansao academica 703
// Linha complementar para expansao academica 704
// Linha complementar para expansao academica 705
// Linha complementar para expansao academica 706
// Linha complementar para expansao academica 707
// Linha complementar para expansao academica 708
// Linha complementar para expansao academica 709
// Linha complementar para expansao academica 710
// Linha complementar para expansao academica 711
// Linha complementar para expansao academica 712
// Linha complementar para expansao academica 713
// Linha complementar para expansao academica 714
// Linha complementar para expansao academica 715
// Linha complementar para expansao academica 716
// Linha complementar para expansao academica 717
// Linha complementar para expansao academica 718
// Linha complementar para expansao academica 719
// Linha complementar para expansao academica 720
// Linha complementar para expansao academica 721
// Linha complementar para expansao academica 722
// Linha complementar para expansao academica 723
// Linha complementar para expansao academica 724
// Linha complementar para expansao academica 725
// Linha complementar para expansao academica 726
// Linha complementar para expansao academica 727
// Linha complementar para expansao academica 728
// Linha complementar para expansao academica 729
// Linha complementar para expansao academica 730
// Linha complementar para expansao academica 731
// Linha complementar para expansao academica 732
// Linha complementar para expansao academica 733
// Linha complementar para expansao academica 734
// Linha complementar para expansao academica 735
// Linha complementar para expansao academica 736
// Linha complementar para expansao academica 737
// Linha complementar para expansao academica 738
// Linha complementar para expansao academica 739
// Linha complementar para expansao academica 740
// Linha complementar para expansao academica 741
// Linha complementar para expansao academica 742
// Linha complementar para expansao academica 743
// Linha complementar para expansao academica 744
// Linha complementar para expansao academica 745
// Linha complementar para expansao academica 746
// Linha complementar para expansao academica 747
// Linha complementar para expansao academica 748
// Linha complementar para expansao academica 749
// Linha complementar para expansao academica 750
// Linha complementar para expansao academica 751
// Linha complementar para expansao academica 752
// Linha complementar para expansao academica 753
// Linha complementar para expansao academica 754
// Linha complementar para expansao academica 755
// Linha complementar para expansao academica 756
// Linha complementar para expansao academica 757
// Linha complementar para expansao academica 758
// Linha complementar para expansao academica 759
// Linha complementar para expansao academica 760
// Linha complementar para expansao academica 761
// Linha complementar para expansao academica 762
// Linha complementar para expansao academica 763
// Linha complementar para expansao academica 764
// Linha complementar para expansao academica 765
// Linha complementar para expansao academica 766
// Linha complementar para expansao academica 767
// Linha complementar para expansao academica 768
// Linha complementar para expansao academica 769
// Linha complementar para expansao academica 770
// Linha complementar para expansao academica 771
// Linha complementar para expansao academica 772
// Linha complementar para expansao academica 773
// Linha complementar para expansao academica 774
// Linha complementar para expansao academica 775
// Linha complementar para expansao academica 776
// Linha complementar para expansao academica 777
// Linha complementar para expansao academica 778
// Linha complementar para expansao academica 779
// Linha complementar para expansao academica 780
// Linha complementar para expansao academica 781
// Linha complementar para expansao academica 782
// Linha complementar para expansao academica 783
// Linha complementar para expansao academica 784
// Linha complementar para expansao academica 785
// Linha complementar para expansao academica 786
// Linha complementar para expansao academica 787
// Linha complementar para expansao academica 788
// Linha complementar para expansao academica 789
// Linha complementar para expansao academica 790
// Linha complementar para expansao academica 791
// Linha complementar para expansao academica 792
// Linha complementar para expansao academica 793
// Linha complementar para expansao academica 794
// Linha complementar para expansao academica 795
// Linha complementar para expansao academica 796
// Linha complementar para expansao academica 797
// Linha complementar para expansao academica 798
// Linha complementar para expansao academica 799
// Linha complementar para expansao academica 800
// Linha complementar para expansao academica 801
// Linha complementar para expansao academica 802
// Linha complementar para expansao academica 803
// Linha complementar para expansao academica 804
// Linha complementar para expansao academica 805
// Linha complementar para expansao academica 806
// Linha complementar para expansao academica 807
// Linha complementar para expansao academica 808
// Linha complementar para expansao academica 809
// Linha complementar para expansao academica 810
// Linha complementar para expansao academica 811
// Linha complementar para expansao academica 812
// Linha complementar para expansao academica 813
// Linha complementar para expansao academica 814
// Linha complementar para expansao academica 815
// Linha complementar para expansao academica 816
// Linha complementar para expansao academica 817
// Linha complementar para expansao academica 818
// Linha complementar para expansao academica 819
// Linha complementar para expansao academica 820
// Linha complementar para expansao academica 821
// Linha complementar para expansao academica 822
// Linha complementar para expansao academica 823
// Linha complementar para expansao academica 824
// Linha complementar para expansao academica 825
// Linha complementar para expansao academica 826
// Linha complementar para expansao academica 827
// Linha complementar para expansao academica 828
// Linha complementar para expansao academica 829
// Linha complementar para expansao academica 830
// Linha complementar para expansao academica 831
// Linha complementar para expansao academica 832
// Linha complementar para expansao academica 833
// Linha complementar para expansao academica 834
// Linha complementar para expansao academica 835
// Linha complementar para expansao academica 836
// Linha complementar para expansao academica 837
// Linha complementar para expansao academica 838
// Linha complementar para expansao academica 839
// Linha complementar para expansao academica 840
// Linha complementar para expansao academica 841
// Linha complementar para expansao academica 842
// Linha complementar para expansao academica 843
// Linha complementar para expansao academica 844
// Linha complementar para expansao academica 845
// Linha complementar para expansao academica 846
// Linha complementar para expansao academica 847
// Linha complementar para expansao academica 848
// Linha complementar para expansao academica 849
// Linha complementar para expansao academica 850
// Linha complementar para expansao academica 851
// Linha complementar para expansao academica 852
// Linha complementar para expansao academica 853
// Linha complementar para expansao academica 854
// Linha complementar para expansao academica 855
// Linha complementar para expansao academica 856
// Linha complementar para expansao academica 857
// Linha complementar para expansao academica 858
// Linha complementar para expansao academica 859
// Linha complementar para expansao academica 860
// Linha complementar para expansao academica 861
// Linha complementar para expansao academica 862
// Linha complementar para expansao academica 863
// Linha complementar para expansao academica 864
// Linha complementar para expansao academica 865
// Linha complementar para expansao academica 866
// Linha complementar para expansao academica 867
// Linha complementar para expansao academica 868
// Linha complementar para expansao academica 869
// Linha complementar para expansao academica 870
// Linha complementar para expansao academica 871
// Linha complementar para expansao academica 872
// Linha complementar para expansao academica 873
// Linha complementar para expansao academica 874
// Linha complementar para expansao academica 875
// Linha complementar para expansao academica 876
// Linha complementar para expansao academica 877
// Linha complementar para expansao academica 878
// Linha complementar para expansao academica 879
// Linha complementar para expansao academica 880
// Linha complementar para expansao academica 881
// Linha complementar para expansao academica 882
// Linha complementar para expansao academica 883
// Linha complementar para expansao academica 884
// Linha complementar para expansao academica 885
// Linha complementar para expansao academica 886
// Linha complementar para expansao academica 887
// Linha complementar para expansao academica 888
// Linha complementar para expansao academica 889
// Linha complementar para expansao academica 890
// Linha complementar para expansao academica 891
// Linha complementar para expansao academica 892
// Linha complementar para expansao academica 893
// Linha complementar para expansao academica 894
// Linha complementar para expansao academica 895
// Linha complementar para expansao academica 896
// Linha complementar para expansao academica 897
// Linha complementar para expansao academica 898
// Linha complementar para expansao academica 899
// Linha complementar para expansao academica 900
// Linha complementar para expansao academica 901
// Linha complementar para expansao academica 902
// Linha complementar para expansao academica 903
// Linha complementar para expansao academica 904
// Linha complementar para expansao academica 905
// Linha complementar para expansao academica 906
// Linha complementar para expansao academica 907
// Linha complementar para expansao academica 908
// Linha complementar para expansao academica 909
// Linha complementar para expansao academica 910
// Linha complementar para expansao academica 911
// Linha complementar para expansao academica 912
// Linha complementar para expansao academica 913
// Linha complementar para expansao academica 914
// Linha complementar para expansao academica 915
// Linha complementar para expansao academica 916
// Linha complementar para expansao academica 917
// Linha complementar para expansao academica 918
// Linha complementar para expansao academica 919
// Linha complementar para expansao academica 920
// Linha complementar para expansao academica 921
// Linha complementar para expansao academica 922
// Linha complementar para expansao academica 923
// Linha complementar para expansao academica 924
// Linha complementar para expansao academica 925
// Linha complementar para expansao academica 926
// Linha complementar para expansao academica 927
// Linha complementar para expansao academica 928
// Linha complementar para expansao academica 929
// Linha complementar para expansao academica 930
// Linha complementar para expansao academica 931
// Linha complementar para expansao academica 932
// Linha complementar para expansao academica 933
// Linha complementar para expansao academica 934
// Linha complementar para expansao academica 935
// Linha complementar para expansao academica 936
// Linha complementar para expansao academica 937
// Linha complementar para expansao academica 938
// Linha complementar para expansao academica 939
// Linha complementar para expansao academica 940
// Linha complementar para expansao academica 941
// Linha complementar para expansao academica 942
// Linha complementar para expansao academica 943
// Linha complementar para expansao academica 944
// Linha complementar para expansao academica 945
// Linha complementar para expansao academica 946
// Linha complementar para expansao academica 947
// Linha complementar para expansao academica 948
// Linha complementar para expansao academica 949
