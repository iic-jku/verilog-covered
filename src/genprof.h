#ifndef __GENPROF_H__
#define __GENPROF_H__

/*
 Copyright (c) 2006 Trevor Williams

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by the Free Software
 Foundation; either version 2 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with this program;
 if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/*!
 \file    genprof.h
 \author  Trevor Williams  (phase1geo@gmail.com)
 \date    12/10/2007
*/

#include "defines.h"

#define NUM_PROFILES 1010

#ifdef DEBUG
#define UNREGISTERED 0
#define ARC_FIND_FROM_STATE 1
#define ARC_FIND_TO_STATE 2
#define ARC_FIND_ARC 3
#define ARC_FIND_ARC_BY_EXCLUSION_ID 4
#define ARC_CREATE 5
#define ARC_ADD 6
#define ARC_STATE_HITS 7
#define ARC_TRANSITION_HITS 8
#define ARC_TRANSITION_EXCLUDED 9
#define ARC_GET_STATS 10
#define ARC_DB_WRITE 11
#define ARC_DB_READ 12
#define ARC_DB_MERGE 13
#define ARC_MERGE 14
#define ARC_GET_STATES 15
#define ARC_GET_TRANSITIONS 16
#define ARC_ARE_ANY_EXCLUDED 17
#define ARC_DEALLOC 18
#define ASSERTION_PARSE 19
#define ASSERTION_PARSE_ATTR 20
#define ASSERTION_GET_STATS 21
#define ASSERTION_DISPLAY_INSTANCE_SUMMARY 22
#define ASSERTION_INSTANCE_SUMMARY 23
#define ASSERTION_DISPLAY_FUNIT_SUMMARY 24
#define ASSERTION_FUNIT_SUMMARY 25
#define ASSERTION_DISPLAY_VERBOSE 26
#define ASSERTION_INSTANCE_VERBOSE 27
#define ASSERTION_FUNIT_VERBOSE 28
#define ASSERTION_REPORT 29
#define ASSERTION_GET_FUNIT_SUMMARY 30
#define ASSERTION_COLLECT 31
#define ASSERTION_GET_COVERAGE 32
#define ATTRIBUTE_CREATE 33
#define ATTRIBUTE_PARSE 34
#define ATTRIBUTE_DEALLOC 35
#define BIND_ADD 36
#define BIND_APPEND_FSM_EXPR 37
#define BIND_REMOVE 38
#define BIND_FIND_SIG_NAME 39
#define BIND_PARAM 40
#define BIND_SIGNAL 41
#define BIND_TASK_FUNCTION_PORTS 42
#define BIND_TASK_FUNCTION_NAMEDBLOCK 43
#define BIND_PERFORM 44
#define BIND_DEALLOC 45
#define CODEGEN_CREATE_EXPR_HELPER 46
#define CODEGEN_CREATE_EXPR 47
#define CODEGEN_GEN_EXPR 48
#define COMBINATION_CALC_DEPTH 49
#define COMBINATION_DOES_MULTI_EXP_NEED_UL 50
#define COMBINATION_MULTI_EXPR_CALC 51
#define COMBINATION_IS_EXPR_MULTI_NODE 52
#define COMBINATION_GET_TREE_STATS 53
#define COMBINATION_RESET_COUNTED_EXPRS 54
#define COMBINATION_RESET_COUNTED_EXPR_TREE 55
#define COMBINATION_GET_STATS 56
#define COMBINATION_GET_FUNIT_SUMMARY 57
#define COMBINATION_GET_INST_SUMMARY 58
#define COMBINATION_DISPLAY_INSTANCE_SUMMARY 59
#define COMBINATION_INSTANCE_SUMMARY 60
#define COMBINATION_DISPLAY_FUNIT_SUMMARY 61
#define COMBINATION_FUNIT_SUMMARY 62
#define COMBINATION_DRAW_LINE 63
#define COMBINATION_DRAW_CENTERED_LINE 64
#define COMBINATION_UNDERLINE_TREE 65
#define COMBINATION_PREP_LINE 66
#define COMBINATION_UNDERLINE 67
#define COMBINATION_UNARY 68
#define COMBINATION_EVENT 69
#define COMBINATION_TWO_VARS 70
#define COMBINATION_MULTI_VAR_EXPRS 71
#define COMBINATION_MULTI_EXPR_OUTPUT_LENGTH 72
#define COMBINATION_MULTI_EXPR_OUTPUT 73
#define COMBINATION_MULTI_VARS 74
#define COMBINATION_GET_MISSED_EXPR 75
#define COMBINATION_LIST_MISSED 76
#define COMBINATION_OUTPUT_EXPR 77
#define COMBINATION_DISPLAY_VERBOSE 78
#define COMBINATION_INSTANCE_VERBOSE 79
#define COMBINATION_FUNIT_VERBOSE 80
#define COMBINATION_COLLECT 81
#define COMBINATION_GET_EXCLUDE_LIST 82
#define COMBINATION_GET_EXPRESSION 83
#define COMBINATION_GET_COVERAGE 84
#define COMBINATION_REPORT 85
#define DB_CREATE 86
#define DB_CLOSE 87
#define DB_CHECK_FOR_TOP_MODULE 88
#define DB_WRITE 89
#define DB_READ 90
#define DB_MERGE_FUNITS 91
#define DB_SCALE_TO_PRECISION 92
#define DB_CREATE_UNNAMED_SCOPE 93
#define DB_IS_UNNAMED_SCOPE 94
#define DB_SET_TIMESCALE 95
#define DB_GET_CURR_FUNIT 96
#define DB_GET_EXCLUSION_ID_SIZE 97
#define DB_GEN_EXCLUSION_ID 98
#define DB_ADD_FILE_VERSION 99
#define DB_ADD_INSTANCE 100
#define DB_ADD_MODULE 101
#define DB_END_MODULE 102
#define DB_ADD_FUNCTION_TASK_NAMEDBLOCK 103
#define DB_END_FUNCTION_TASK_NAMEDBLOCK 104
#define DB_ADD_DECLARED_PARAM 105
#define DB_ADD_OVERRIDE_PARAM 106
#define DB_ADD_VECTOR_PARAM 107
#define DB_ADD_DEFPARAM 108
#define DB_ADD_SIGNAL 109
#define DB_ADD_ENUM 110
#define DB_END_ENUM_LIST 111
#define DB_ADD_TYPEDEF 112
#define DB_FIND_SIGNAL 113
#define DB_ADD_GEN_ITEM_BLOCK 114
#define DB_FIND_GEN_ITEM 115
#define DB_FIND_TYPEDEF 116
#define DB_GET_CURR_GEN_BLOCK 117
#define DB_CURR_SIGNAL_COUNT 118
#define DB_CREATE_EXPRESSION 119
#define DB_BIND_EXPR_TREE 120
#define DB_CREATE_EXPR_FROM_STATIC 121
#define DB_ADD_EXPRESSION 122
#define DB_CREATE_SENSITIVITY_LIST 123
#define DB_PARALLELIZE_STATEMENT 124
#define DB_CREATE_STATEMENT 125
#define DB_ADD_STATEMENT 126
#define DB_REMOVE_STATEMENT_FROM_CURRENT_FUNIT 127
#define DB_REMOVE_STATEMENT 128
#define DB_CONNECT_STATEMENT_TRUE 129
#define DB_CONNECT_STATEMENT_FALSE 130
#define DB_GEN_ITEM_CONNECT_TRUE 131
#define DB_GEN_ITEM_CONNECT_FALSE 132
#define DB_GEN_ITEM_CONNECT 133
#define DB_STATEMENT_CONNECT 134
#define DB_CREATE_ATTR_PARAM 135
#define DB_PARSE_ATTRIBUTE 136
#define DB_REMOVE_STMT_BLKS_CALLING_STATEMENT 137
#define DB_GEN_CURR_INST_SCOPE 138
#define DB_SYNC_CURR_INSTANCE 139
#define DB_SET_VCD_SCOPE 140
#define DB_VCD_UPSCOPE 141
#define DB_ASSIGN_SYMBOL 142
#define DB_SET_SYMBOL_CHAR 143
#define DB_SET_SYMBOL_STRING 144
#define DB_DO_TIMESTEP 145
#define ENUMERATE_ADD_ITEM 146
#define ENUMERATE_END_LIST 147
#define ENUMERATE_RESOLVE 148
#define ENUMERATE_DEALLOC 149
#define ENUMERATE_DEALLOC_LIST 150
#define EXCLUDE_EXPR_ASSIGN_AND_RECALC 151
#define EXCLUDE_SIG_ASSIGN_AND_RECALC 152
#define EXCLUDE_ARC_ASSIGN_AND_RECALC 153
#define EXCLUDE_ADD_EXCLUDE_REASON 154
#define EXCLUDE_REMOVE_EXCLUDE_REASON 155
#define EXCLUDE_IS_LINE_EXCLUDED 156
#define EXCLUDE_SET_LINE_EXCLUDE 157
#define EXCLUDE_IS_TOGGLE_EXCLUDED 158
#define EXCLUDE_SET_TOGGLE_EXCLUDE 159
#define EXCLUDE_IS_COMB_EXCLUDED 160
#define EXCLUDE_SET_COMB_EXCLUDE 161
#define EXCLUDE_IS_FSM_EXCLUDED 162
#define EXCLUDE_SET_FSM_EXCLUDE 163
#define EXCLUDE_IS_ASSERT_EXCLUDED 164
#define EXCLUDE_SET_ASSERT_EXCLUDE 165
#define EXCLUDE_FIND_EXCLUDE_REASON 166
#define EXCLUDE_DB_WRITE 167
#define EXCLUDE_DB_READ 168
#define EXCLUDE_RESOLVE_REASON 169
#define EXCLUDE_DB_MERGE 170
#define EXCLUDE_FIND_SIGNAL 171
#define EXCLUDE_FIND_EXPRESSION 172
#define EXCLUDE_FIND_FSM_ARC 173
#define EXCLUDE_FORMAT_REASON 174
#define EXCLUDED_GET_MESSAGE 175
#define EXCLUDE_HANDLE_EXCLUDE_REASON 176
#define EXCLUDE_PRINT_EXCLUSION 177
#define EXCLUDE_LINE_FROM_ID 178
#define EXCLUDE_TOGGLE_FROM_ID 179
#define EXCLUDE_MEMORY_FROM_ID 180
#define EXCLUDE_EXPR_FROM_ID 181
#define EXCLUDE_FSM_FROM_ID 182
#define EXCLUDE_ASSERT_FROM_ID 183
#define EXCLUDE_APPLY_EXCLUSIONS 184
#define COMMAND_EXCLUDE 185
#define EXPRESSION_CREATE_TMP_VECS 186
#define EXPRESSION_CREATE_VALUE 187
#define EXPRESSION_CREATE 188
#define EXPRESSION_SET_VALUE 189
#define EXPRESSION_SET_SIGNED 190
#define EXPRESSION_RESIZE 191
#define EXPRESSION_GET_ID 192
#define EXPRESSION_GET_FIRST_LINE_EXPR 193
#define EXPRESSION_GET_LAST_LINE_EXPR 194
#define EXPRESSION_GET_CURR_DIMENSION 195
#define EXPRESSION_FIND_RHS_SIGS 196
#define EXPRESSION_FIND_PARAMS 197
#define EXPRESSION_FIND_ULINE_ID 198
#define EXPRESSION_FIND_EXPR 199
#define EXPRESSION_CONTAINS_EXPR_CALLING_STMT 200
#define EXPRESSION_GET_ROOT_STATEMENT 201
#define EXPRESSION_ASSIGN_EXPR_IDS 202
#define EXPRESSION_DB_WRITE 203
#define EXPRESSION_DB_WRITE_TREE 204
#define EXPRESSION_DB_READ 205
#define EXPRESSION_DB_MERGE 206
#define EXPRESSION_MERGE 207
#define EXPRESSION_STRING_OP 208
#define EXPRESSION_STRING 209
#define EXPRESSION_OP_FUNC__XOR 210
#define EXPRESSION_OP_FUNC__XOR_A 211
#define EXPRESSION_OP_FUNC__MULTIPLY 212
#define EXPRESSION_OP_FUNC__MULTIPLY_A 213
#define EXPRESSION_OP_FUNC__DIVIDE 214
#define EXPRESSION_OP_FUNC__DIVIDE_A 215
#define EXPRESSION_OP_FUNC__MOD 216
#define EXPRESSION_OP_FUNC__MOD_A 217
#define EXPRESSION_OP_FUNC__ADD 218
#define EXPRESSION_OP_FUNC__ADD_A 219
#define EXPRESSION_OP_FUNC__SUBTRACT 220
#define EXPRESSION_OP_FUNC__SUB_A 221
#define EXPRESSION_OP_FUNC__AND 222
#define EXPRESSION_OP_FUNC__AND_A 223
#define EXPRESSION_OP_FUNC__OR 224
#define EXPRESSION_OP_FUNC__OR_A 225
#define EXPRESSION_OP_FUNC__NAND 226
#define EXPRESSION_OP_FUNC__NOR 227
#define EXPRESSION_OP_FUNC__NXOR 228
#define EXPRESSION_OP_FUNC__LT 229
#define EXPRESSION_OP_FUNC__GT 230
#define EXPRESSION_OP_FUNC__LSHIFT 231
#define EXPRESSION_OP_FUNC__LSHIFT_A 232
#define EXPRESSION_OP_FUNC__RSHIFT 233
#define EXPRESSION_OP_FUNC__RSHIFT_A 234
#define EXPRESSION_OP_FUNC__ARSHIFT 235
#define EXPRESSION_OP_FUNC__ARSHIFT_A 236
#define EXPRESSION_OP_FUNC__TIME 237
#define EXPRESSION_OP_FUNC__RANDOM 238
#define EXPRESSION_OP_FUNC__SASSIGN 239
#define EXPRESSION_OP_FUNC__SRANDOM 240
#define EXPRESSION_OP_FUNC__URANDOM 241
#define EXPRESSION_OP_FUNC__URANDOM_RANGE 242
#define EXPRESSION_OP_FUNC__EQ 243
#define EXPRESSION_OP_FUNC__CEQ 244
#define EXPRESSION_OP_FUNC__LE 245
#define EXPRESSION_OP_FUNC__GE 246
#define EXPRESSION_OP_FUNC__NE 247
#define EXPRESSION_OP_FUNC__CNE 248
#define EXPRESSION_OP_FUNC__LOR 249
#define EXPRESSION_OP_FUNC__LAND 250
#define EXPRESSION_OP_FUNC__COND 251
#define EXPRESSION_OP_FUNC__COND_SEL 252
#define EXPRESSION_OP_FUNC__UINV 253
#define EXPRESSION_OP_FUNC__UAND 254
#define EXPRESSION_OP_FUNC__UNOT 255
#define EXPRESSION_OP_FUNC__UOR 256
#define EXPRESSION_OP_FUNC__UXOR 257
#define EXPRESSION_OP_FUNC__UNAND 258
#define EXPRESSION_OP_FUNC__UNOR 259
#define EXPRESSION_OP_FUNC__UNXOR 260
#define EXPRESSION_OP_FUNC__NULL 261
#define EXPRESSION_OP_FUNC__SIG 262
#define EXPRESSION_OP_FUNC__SBIT 263
#define EXPRESSION_OP_FUNC__MBIT 264
#define EXPRESSION_OP_FUNC__EXPAND 265
#define EXPRESSION_OP_FUNC__LIST 266
#define EXPRESSION_OP_FUNC__CONCAT 267
#define EXPRESSION_OP_FUNC__PEDGE 268
#define EXPRESSION_OP_FUNC__NEDGE 269
#define EXPRESSION_OP_FUNC__AEDGE 270
#define EXPRESSION_OP_FUNC__EOR 271
#define EXPRESSION_OP_FUNC__SLIST 272
#define EXPRESSION_OP_FUNC__DELAY 273
#define EXPRESSION_OP_FUNC__TRIGGER 274
#define EXPRESSION_OP_FUNC__CASE 275
#define EXPRESSION_OP_FUNC__CASEX 276
#define EXPRESSION_OP_FUNC__CASEZ 277
#define EXPRESSION_OP_FUNC__DEFAULT 278
#define EXPRESSION_OP_FUNC__BASSIGN 279
#define EXPRESSION_OP_FUNC__FUNC_CALL 280
#define EXPRESSION_OP_FUNC__TASK_CALL 281
#define EXPRESSION_OP_FUNC__NB_CALL 282
#define EXPRESSION_OP_FUNC__FORK 283
#define EXPRESSION_OP_FUNC__JOIN 284
#define EXPRESSION_OP_FUNC__DISABLE 285
#define EXPRESSION_OP_FUNC__REPEAT 286
#define EXPRESSION_OP_FUNC__EXPONENT 287
#define EXPRESSION_OP_FUNC__PASSIGN 288
#define EXPRESSION_OP_FUNC__MBIT_POS 289
#define EXPRESSION_OP_FUNC__MBIT_NEG 290
#define EXPRESSION_OP_FUNC__NEGATE 291
#define EXPRESSION_OP_FUNC__IINC 292
#define EXPRESSION_OP_FUNC__PINC 293
#define EXPRESSION_OP_FUNC__IDEC 294
#define EXPRESSION_OP_FUNC__PDEC 295
#define EXPRESSION_OP_FUNC__DLY_ASSIGN 296
#define EXPRESSION_OP_FUNC__DLY_OP 297
#define EXPRESSION_OP_FUNC__REPEAT_DLY 298
#define EXPRESSION_OP_FUNC__DIM 299
#define EXPRESSION_OP_FUNC__WAIT 300
#define EXPRESSION_OP_FUNC__FINISH 301
#define EXPRESSION_OP_FUNC__STOP 302
#define EXPRESSION_OPERATE 303
#define EXPRESSION_OPERATE_RECURSIVELY 304
#define EXPRESSION_IS_STATIC_ONLY 305
#define EXPRESSION_IS_ASSIGNED 306
#define EXPRESSION_IS_BIT_SELECT 307
#define EXPRESSION_IS_LAST_SELECT 308
#define EXPRESSION_IS_IN_RASSIGN 309
#define EXPRESSION_SET_ASSIGNED 310
#define EXPRESSION_SET_CHANGED 311
#define EXPRESSION_ASSIGN 312
#define EXPRESSION_DEALLOC 313
#define FSM_CREATE 314
#define FSM_ADD_ARC 315
#define FSM_CREATE_TABLES 316
#define FSM_DB_WRITE 317
#define FSM_DB_READ 318
#define FSM_DB_MERGE 319
#define FSM_MERGE 320
#define FSM_TABLE_SET 321
#define FSM_GET_STATS 322
#define FSM_GET_FUNIT_SUMMARY 323
#define FSM_GET_INST_SUMMARY 324
#define FSM_GATHER_SIGNALS 325
#define FSM_COLLECT 326
#define FSM_GET_COVERAGE 327
#define FSM_DISPLAY_INSTANCE_SUMMARY 328
#define FSM_INSTANCE_SUMMARY 329
#define FSM_DISPLAY_FUNIT_SUMMARY 330
#define FSM_FUNIT_SUMMARY 331
#define FSM_DISPLAY_STATE_VERBOSE 332
#define FSM_DISPLAY_ARC_VERBOSE 333
#define FSM_DISPLAY_VERBOSE 334
#define FSM_INSTANCE_VERBOSE 335
#define FSM_FUNIT_VERBOSE 336
#define FSM_REPORT 337
#define FSM_DEALLOC 338
#define FSM_ARG_PARSE_STATE 339
#define FSM_ARG_PARSE 340
#define FSM_ARG_PARSE_VALUE 341
#define FSM_ARG_PARSE_TRANS 342
#define FSM_ARG_PARSE_ATTR 343
#define FSM_VAR_ADD 344
#define FSM_VAR_IS_OUTPUT_STATE 345
#define FSM_VAR_BIND_EXPR 346
#define FSM_VAR_ADD_EXPR 347
#define FSM_VAR_BIND_STMT 348
#define FSM_VAR_BIND_ADD 349
#define FSM_VAR_STMT_ADD 350
#define FSM_VAR_BIND 351
#define FSM_VAR_DEALLOC 352
#define FSM_VAR_REMOVE 353
#define FSM_VAR_CLEANUP 354
#define FUNC_ITER_DISPLAY 355
#define FUNC_ITER_SORT 356
#define FUNC_ITER_COUNT_STMT_ITERS 357
#define FUNC_ITER_ADD_STMT_ITERS 358
#define FUNC_ITER_ADD_SIG_LINKS 359
#define FUNC_ITER_INIT 360
#define FUNC_ITER_GET_NEXT_STATEMENT 361
#define FUNC_ITER_GET_NEXT_SIGNAL 362
#define FUNC_ITER_DEALLOC 363
#define FUNIT_INIT 364
#define FUNIT_CREATE 365
#define FUNIT_GET_CURR_MODULE 366
#define FUNIT_GET_CURR_MODULE_SAFE 367
#define FUNIT_GET_CURR_FUNCTION 368
#define FUNIT_GET_CURR_TASK 369
#define FUNIT_GET_PORT_COUNT 370
#define FUNIT_FIND_PARAM 371
#define FUNIT_FIND_SIGNAL 372
#define FUNIT_REMOVE_STMT_BLKS_CALLING_STMT 373
#define FUNIT_GEN_TASK_FUNCTION_NAMEDBLOCK_NAME 374
#define FUNIT_SIZE_ELEMENTS 375
#define FUNIT_DB_WRITE 376
#define FUNIT_DB_READ 377
#define FUNIT_VERSION_DB_READ 378
#define FUNIT_DB_MERGE 379
#define FUNIT_MERGE 380
#define FUNIT_FLATTEN_NAME 381
#define FUNIT_FIND_BY_ID 382
#define FUNIT_IS_TOP_MODULE 383
#define FUNIT_IS_UNNAMED 384
#define FUNIT_IS_UNNAMED_CHILD_OF 385
#define FUNIT_IS_CHILD_OF 386
#define FUNIT_DISPLAY_SIGNALS 387
#define FUNIT_DISPLAY_EXPRESSIONS 388
#define STATEMENT_ADD_THREAD 389
#define FUNIT_PUSH_THREADS 390
#define STATEMENT_DELETE_THREAD 391
#define FUNIT_CLEAN 392
#define FUNIT_DEALLOC 393
#define GEN_ITEM_STRINGIFY 394
#define GEN_ITEM_DISPLAY 395
#define GEN_ITEM_DISPLAY_BLOCK_HELPER 396
#define GEN_ITEM_DISPLAY_BLOCK 397
#define GEN_ITEM_COMPARE 398
#define GEN_ITEM_FIND 399
#define GEN_ITEM_REMOVE_IF_CONTAINS_EXPR_CALLING_STMT 400
#define GEN_ITEM_GET_GENVAR 401
#define GEN_ITEM_VARNAME_CONTAINS_GENVAR 402
#define GEN_ITEM_CALC_SIGNAL_NAME 403
#define GEN_ITEM_CREATE_EXPR 404
#define GEN_ITEM_CREATE_SIG 405
#define GEN_ITEM_CREATE_STMT 406
#define GEN_ITEM_CREATE_INST 407
#define GEN_ITEM_CREATE_TFN 408
#define GEN_ITEM_CREATE_BIND 409
#define GEN_ITEM_RESIZE_STMTS_AND_SIGS 410
#define GEN_ITEM_ASSIGN_IDS 411
#define GEN_ITEM_DB_WRITE 412
#define GEN_ITEM_DB_WRITE_EXPR_TREE 413
#define GEN_ITEM_CONNECT 414
#define GEN_ITEM_RESOLVE 415
#define GEN_ITEM_BIND 416
#define GENERATE_RESOLVE 417
#define GENERATE_REMOVE_STMT_HELPER 418
#define GENERATE_REMOVE_STMT 419
#define GEN_ITEM_DEALLOC 420
#define INFO_SET_VECTOR_ELEM_SIZE 421
#define INFO_DB_WRITE 422
#define INFO_DB_READ 423
#define ARGS_DB_READ 424
#define MESSAGE_DB_READ 425
#define MERGED_CDD_DB_READ 426
#define INFO_DEALLOC 427
#define INSTANCE_DISPLAY_TREE_HELPER 428
#define INSTANCE_DISPLAY_TREE 429
#define INSTANCE_CREATE 430
#define INSTANCE_GEN_SCOPE 431
#define INSTANCE_COMPARE 432
#define INSTANCE_FIND_SCOPE 433
#define INSTANCE_FIND_BY_FUNIT 434
#define INSTANCE_FIND_SIGNAL_BY_EXCLUSION_ID 435
#define INSTANCE_FIND_EXPRESSION_BY_EXCLUSION_ID 436
#define INSTANCE_FIND_FSM_ARC_INDEX_BY_EXCLUSION_ID 437
#define INSTANCE_ADD_CHILD 438
#define INSTANCE_COPY 439
#define INSTANCE_ATTACH_CHILD 440
#define INSTANCE_PARSE_ADD 441
#define INSTANCE_RESOLVE_INST 442
#define INSTANCE_RESOLVE_HELPER 443
#define INSTANCE_RESOLVE 444
#define INSTANCE_READ_ADD 445
#define INSTANCE_DB_WRITE 446
#define INSTANCE_FLATTEN_HELPER 447
#define INSTANCE_FLATTEN 448
#define INSTANCE_REMOVE_STMT_BLKS_CALLING_STMT 449
#define INSTANCE_REMOVE_PARMS_WITH_EXPR 450
#define INSTANCE_DEALLOC_SINGLE 451
#define INSTANCE_DEALLOC_TREE 452
#define INSTANCE_DEALLOC 453
#define STMT_ITER_RESET 454
#define STMT_ITER_COPY 455
#define STMT_ITER_NEXT 456
#define STMT_ITER_REVERSE 457
#define STMT_ITER_FIND_HEAD 458
#define STMT_ITER_GET_NEXT_IN_ORDER 459
#define STMT_ITER_GET_LINE_BEFORE 460
#define LEXER_KEYWORD_1995_CODE 461
#define LEXER_KEYWORD_2001_CODE 462
#define LEXER_KEYWORD_SV_CODE 463
#define LEXER_KEYWORD_SYS_1995_CODE 464
#define LEXER_KEYWORD_SYS_2001_CODE 465
#define LEXER_KEYWORD_SYS_SV_CODE 466
#define LEXER_CSTRING_A 467
#define LEXER_KEYWORD_A 468
#define LEXER_ESCAPED_NAME 469
#define LEXER_SYSTEM_CALL 470
#define LINE_DIRECTIVE 471
#define LINE_DIRECTIVE2 472
#define PROCESS_TIMESCALE_TOKEN 473
#define PROCESS_TIMESCALE 474
#define LEXER_YYWRAP 475
#define RESET_LEXER 476
#define CHECK_FOR_PRAGMA 477
#define LINE_GET_STATS 478
#define LINE_COLLECT 479
#define LINE_GET_FUNIT_SUMMARY 480
#define LINE_GET_INST_SUMMARY 481
#define LINE_DISPLAY_INSTANCE_SUMMARY 482
#define LINE_INSTANCE_SUMMARY 483
#define LINE_DISPLAY_FUNIT_SUMMARY 484
#define LINE_FUNIT_SUMMARY 485
#define LINE_DISPLAY_VERBOSE 486
#define LINE_INSTANCE_VERBOSE 487
#define LINE_FUNIT_VERBOSE 488
#define LINE_REPORT 489
#define STR_LINK_ADD 490
#define STMT_LINK_ADD_HEAD 491
#define STMT_LINK_ADD_TAIL 492
#define STMT_LINK_MERGE 493
#define EXP_LINK_ADD 494
#define SIG_LINK_ADD 495
#define FSM_LINK_ADD 496
#define FUNIT_LINK_ADD 497
#define GITEM_LINK_ADD 498
#define INST_LINK_ADD 499
#define STR_LINK_FIND 500
#define STMT_LINK_FIND 501
#define EXP_LINK_FIND 502
#define SIG_LINK_FIND 503
#define FSM_LINK_FIND 504
#define FUNIT_LINK_FIND 505
#define GITEM_LINK_FIND 506
#define INST_LINK_FIND_BY_SCOPE 507
#define INST_LINK_FIND_BY_FUNIT 508
#define STR_LINK_REMOVE 509
#define EXP_LINK_REMOVE 510
#define GITEM_LINK_REMOVE 511
#define FUNIT_LINK_REMOVE 512
#define INST_LINK_FLATTEN 513
#define STR_LINK_DELETE_LIST 514
#define STMT_LINK_UNLINK 515
#define STMT_LINK_DELETE_LIST 516
#define EXP_LINK_DELETE_LIST 517
#define SIG_LINK_DELETE_LIST 518
#define FSM_LINK_DELETE_LIST 519
#define FUNIT_LINK_DELETE_LIST 520
#define GITEM_LINK_DELETE_LIST 521
#define INST_LINK_DELETE_LIST 522
#define VCDID 523
#define VCD_CALLBACK 524
#define LXT_PARSE 525
#define LXT2_RD_EXPAND_INTEGER_TO_BITS 526
#define LXT2_RD_EXPAND_BITS_TO_INTEGER 527
#define LXT2_RD_ITER_RADIX 528
#define LXT2_RD_ITER_RADIX0 529
#define LXT2_RD_BUILD_RADIX 530
#define LXT2_RD_REGENERATE_PROCESS_MASK 531
#define LXT2_RD_PROCESS_BLOCK 532
#define LXT2_RD_INIT 533
#define LXT2_RD_CLOSE 534
#define LXT2_RD_GET_FACNAME 535
#define LXT2_RD_ITER_BLOCKS 536
#define LXT2_RD_LIMIT_TIME_RANGE 537
#define LXT2_RD_UNLIMIT_TIME_RANGE 538
#define MEMORY_GET_STAT 539
#define MEMORY_GET_STATS 540
#define MEMORY_GET_FUNIT_SUMMARY 541
#define MEMORY_GET_INST_SUMMARY 542
#define MEMORY_CREATE_PDIM_BIT_ARRAY 543
#define MEMORY_GET_MEM_COVERAGE 544
#define MEMORY_GET_COVERAGE 545
#define MEMORY_COLLECT 546
#define MEMORY_DISPLAY_TOGGLE_INSTANCE_SUMMARY 547
#define MEMORY_TOGGLE_INSTANCE_SUMMARY 548
#define MEMORY_DISPLAY_AE_INSTANCE_SUMMARY 549
#define MEMORY_AE_INSTANCE_SUMMARY 550
#define MEMORY_DISPLAY_TOGGLE_FUNIT_SUMMARY 551
#define MEMORY_TOGGLE_FUNIT_SUMMARY 552
#define MEMORY_DISPLAY_AE_FUNIT_SUMMARY 553
#define MEMORY_AE_FUNIT_SUMMARY 554
#define MEMORY_DISPLAY_MEMORY 555
#define MEMORY_DISPLAY_VERBOSE 556
#define MEMORY_INSTANCE_VERBOSE 557
#define MEMORY_FUNIT_VERBOSE 558
#define MEMORY_REPORT 559
#define COMMAND_MERGE 560
#define OBFUSCATE_SET_MODE 561
#define OBFUSCATE_NAME 562
#define OBFUSCATE_DEALLOC 563
#define OVL_IS_ASSERTION_NAME 564
#define OVL_IS_ASSERTION_MODULE 565
#define OVL_IS_COVERAGE_POINT 566
#define OVL_ADD_ASSERTIONS_TO_NO_SCORE_LIST 567
#define OVL_GET_FUNIT_STATS 568
#define OVL_GET_COVERAGE_POINT 569
#define OVL_DISPLAY_VERBOSE 570
#define OVL_COLLECT 571
#define OVL_GET_COVERAGE 572
#define MOD_PARM_FIND 573
#define MOD_PARM_FIND_EXPR_AND_REMOVE 574
#define MOD_PARM_ADD 575
#define INST_PARM_FIND 576
#define INST_PARM_ADD 577
#define INST_PARM_ADD_GENVAR 578
#define INST_PARM_BIND 579
#define DEFPARAM_ADD 580
#define DEFPARAM_DEALLOC 581
#define PARAM_FIND_AND_SET_EXPR_VALUE 582
#define PARAM_SET_SIG_SIZE 583
#define PARAM_SIZE_FUNCTION 584
#define PARAM_EXPR_EVAL 585
#define PARAM_HAS_OVERRIDE 586
#define PARAM_HAS_DEFPARAM 587
#define PARAM_RESOLVE_DECLARED 588
#define PARAM_RESOLVE_OVERRIDE 589
#define PARAM_RESOLVE 590
#define PARAM_DB_WRITE 591
#define MOD_PARM_DEALLOC 592
#define INST_PARM_DEALLOC 593
#define PARSE_READLINE 594
#define PARSE_DESIGN 595
#define PARSE_AND_SCORE_DUMPFILE 596
#define PARSER_PORT_DECLARATION_A 597
#define PARSER_PORT_DECLARATION_B 598
#define PARSER_PORT_DECLARATION_C 599
#define PARSER_STATIC_EXPR_PRIMARY_A 600
#define PARSER_STATIC_EXPR_PRIMARY_B 601
#define PARSER_EXPRESSION_LIST_A 602
#define PARSER_EXPRESSION_LIST_B 603
#define PARSER_EXPRESSION_LIST_C 604
#define PARSER_EXPRESSION_LIST_D 605
#define PARSER_IDENTIFIER_A 606
#define PARSER_GENERATE_CASE_ITEM_A 607
#define PARSER_GENERATE_CASE_ITEM_B 608
#define PARSER_GENERATE_CASE_ITEM_C 609
#define PARSER_STATEMENT_BEGIN_A 610
#define PARSER_STATEMENT_FORK_A 611
#define PARSER_STATEMENT_FOR_A 612
#define PARSER_CASE_ITEM_A 613
#define PARSER_CASE_ITEM_B 614
#define PARSER_CASE_ITEM_C 615
#define PARSER_DELAY_VALUE_A 616
#define PARSER_DELAY_VALUE_B 617
#define PARSER_PARAMETER_VALUE_BYNAME_A 618
#define PARSER_GATE_INSTANCE_A 619
#define PARSER_GATE_INSTANCE_B 620
#define PARSER_GATE_INSTANCE_C 621
#define PARSER_GATE_INSTANCE_D 622
#define PARSER_LIST_OF_NAMES_A 623
#define PARSER_LIST_OF_NAMES_B 624
#define VLERROR 625
#define VLWARN 626
#define PARSER_DEALLOC_SIG_RANGE 627
#define PARSER_COPY_CURR_RANGE 628
#define PARSER_COPY_RANGE_TO_CURR_RANGE 629
#define PARSER_EXPLICITLY_SET_CURR_RANGE 630
#define PARSER_IMPLICITLY_SET_CURR_RANGE 631
#define PARSER_CHECK_GENERATION 632
#define PERF_GEN_STATS 633
#define PERF_OUTPUT_MOD_STATS 634
#define PERF_OUTPUT_INST_REPORT_HELPER 635
#define PERF_OUTPUT_INST_REPORT 636
#define DEF_LOOKUP 637
#define IS_DEFINED 638
#define DEF_MATCH 639
#define DEF_START 640
#define DEFINE_MACRO 641
#define DO_DEFINE 642
#define DEF_IS_DONE 643
#define DEF_FINISH 644
#define DEF_UNDEFINE 645
#define INCLUDE_FILENAME 646
#define DO_INCLUDE 647
#define YYWRAP 648
#define RESET_PPLEXER 649
#define RACE_BLK_CREATE 650
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT_HELPER 651
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT 652
#define RACE_GET_HEAD_STATEMENT 653
#define RACE_FIND_HEAD_STATEMENT 654
#define RACE_CALC_STMT_BLK_TYPE 655
#define RACE_CALC_EXPR_ASSIGNMENT 656
#define RACE_CALC_ASSIGNMENTS 657
#define RACE_HANDLE_RACE_CONDITION 658
#define RACE_CHECK_ASSIGNMENT_TYPES 659
#define RACE_CHECK_ONE_BLOCK_ASSIGNMENT 660
#define RACE_CHECK_RACE_COUNT 661
#define RACE_CHECK_MODULES 662
#define RACE_DB_WRITE 663
#define RACE_DB_READ 664
#define RACE_GET_STATS 665
#define RACE_REPORT_SUMMARY 666
#define RACE_REPORT_VERBOSE 667
#define RACE_REPORT 668
#define RACE_COLLECT_LINES 669
#define RACE_BLK_DELETE_LIST 670
#define RANK_CREATE_COMP_CDD_COV 671
#define RANK_DEALLOC_COMP_CDD_COV 672
#define RANK_CHECK_INDEX 673
#define RANK_GATHER_SIGNAL_COV 674
#define RANK_GATHER_COMB_COV 675
#define RANK_GATHER_EXPRESSION_COV 676
#define RANK_GATHER_FSM_COV 677
#define RANK_CALC_NUM_CPS 678
#define RANK_GATHER_COMP_CDD_COV 679
#define RANK_READ_CDD 680
#define RANK_SELECTED_CDD_COV 681
#define RANK_PERFORM_WEIGHTED_SELECTION 682
#define RANK_PERFORM_GREEDY_SORT 683
#define RANK_COUNT_CPS 684
#define RANK_PERFORM 685
#define RANK_OUTPUT 686
#define COMMAND_RANK 687
#define REENTRANT_COUNT_AFU_BITS 688
#define REENTRANT_STORE_DATA_BITS 689
#define REENTRANT_RESTORE_DATA_BITS 690
#define REENTRANT_CREATE 691
#define REENTRANT_DEALLOC 692
#define REPORT_PARSE_METRICS 693
#define REPORT_PARSE_ARGS 694
#define REPORT_GATHER_INSTANCE_STATS 695
#define REPORT_GATHER_FUNIT_STATS 696
#define REPORT_PRINT_HEADER 697
#define REPORT_GENERATE 698
#define REPORT_READ_CDD_AND_READY 699
#define REPORT_CLOSE_CDD 700
#define REPORT_SAVE_CDD 701
#define REPORT_FORMAT_EXCLUSION_REASON 702
#define REPORT_OUTPUT_EXCLUSION_REASON 703
#define COMMAND_REPORT 704
#define SCOPE_FIND_FUNIT_FROM_SCOPE 705
#define SCOPE_FIND_PARAM 706
#define SCOPE_FIND_SIGNAL 707
#define SCOPE_FIND_TASK_FUNCTION_NAMEDBLOCK 708
#define SCOPE_GET_PARENT_FUNIT 709
#define SCOPE_GET_PARENT_MODULE 710
#define SCORE_GENERATE_TOP_VPI_MODULE 711
#define SCORE_GENERATE_PLI_TAB_FILE 712
#define SCORE_PARSE_DEFINE 713
#define SCORE_ADD_ARG 714
#define SCORE_PARSE_ARGS 715
#define COMMAND_SCORE 716
#define SEARCH_INIT 717
#define SEARCH_ADD_INCLUDE_PATH 718
#define SEARCH_ADD_DIRECTORY_PATH 719
#define SEARCH_ADD_FILE 720
#define SEARCH_ADD_NO_SCORE_FUNIT 721
#define SEARCH_ADD_EXTENSIONS 722
#define SEARCH_FREE_LISTS 723
#define SIM_CURRENT_THREAD 724
#define SIM_THREAD_POP_HEAD 725
#define SIM_THREAD_INSERT_INTO_DELAY_QUEUE 726
#define SIM_THREAD_PUSH 727
#define SIM_EXPR_CHANGED 728
#define SIM_CREATE_THREAD 729
#define SIM_ADD_THREAD 730
#define SIM_KILL_THREAD 731
#define SIM_KILL_THREAD_WITH_FUNIT 732
#define SIM_ADD_STATICS 733
#define SIM_EXPRESSION 734
#define SIM_THREAD 735
#define SIM_SIMULATE 736
#define SIM_INITIALIZE 737
#define SIM_STOP 738
#define SIM_FINISH 739
#define SIM_DEALLOC 740
#define STATISTIC_CREATE 741
#define STATISTIC_IS_EMPTY 742
#define STATISTIC_DEALLOC 743
#define STATEMENT_CREATE 744
#define STATEMENT_QUEUE_ADD 745
#define STATEMENT_QUEUE_COMPARE 746
#define STATEMENT_SIZE_ELEMENTS 747
#define STATEMENT_DB_WRITE 748
#define STATEMENT_DB_WRITE_TREE 749
#define STATEMENT_DB_WRITE_EXPR_TREE 750
#define STATEMENT_DB_READ 751
#define STATEMENT_ASSIGN_EXPR_IDS 752
#define STATEMENT_CONNECT 753
#define STATEMENT_GET_LAST_LINE_HELPER 754
#define STATEMENT_GET_LAST_LINE 755
#define STATEMENT_FIND_RHS_SIGS 756
#define STATEMENT_FIND_HEAD_STATEMENT 757
#define STATEMENT_FIND_STATEMENT 758
#define STATEMENT_CONTAINS_EXPR_CALLING_STMT 759
#define STATEMENT_DEALLOC_RECURSIVE 760
#define STATEMENT_DEALLOC 761
#define STATIC_EXPR_GEN_UNARY 762
#define STATIC_EXPR_GEN 763
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_PRE 764
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_POST 765
#define STATIC_EXPR_DEALLOC 766
#define STRUCT_UNION_LENGTH 767
#define STRUCT_UNION_ADD_MEMBER 768
#define STRUCT_UNION_ADD_MEMBER_VOID 769
#define STRUCT_UNION_ADD_MEMBER_SIG 770
#define STRUCT_UNION_ADD_MEMBER_TYPEDEF 771
#define STRUCT_UNION_ADD_MEMBER_ENUM 772
#define STRUCT_UNION_ADD_MEMBER_STRUCT_UNION 773
#define STRUCT_UNION_CREATE 774
#define STRUCT_UNION_MEMBER_DEALLOC 775
#define STRUCT_UNION_DEALLOC 776
#define STRUCT_UNION_DEALLOC_LIST 777
#define SYMTABLE_ADD_SYM_SIG 778
#define SYMTABLE_INIT 779
#define SYMTABLE_CREATE 780
#define SYMTABLE_ADD 781
#define SYMTABLE_SET_VALUE 782
#define SYMTABLE_ASSIGN 783
#define SYMTABLE_DEALLOC 784
#define SYS_TASK_UNIFORM 785
#define SYS_TASK_RTL_DIST_UNIFORM 786
#define SYS_TASK_SRANDOM 787
#define SYS_TASK_RANDOM 788
#define SYS_TASK_URANDOM 789
#define SYS_TASK_URANDOM_RANGE 790
#define TCL_FUNC_GET_RACE_REASON_MSGS 791
#define TCL_FUNC_GET_FUNIT_LIST 792
#define TCL_FUNC_GET_INSTANCES 793
#define TCL_FUNC_GET_INSTANCE_LIST 794
#define TCL_FUNC_IS_FUNIT 795
#define TCL_FUNC_GET_FUNIT 796
#define TCL_FUNC_GET_INST 797
#define TCL_FUNC_GET_FUNIT_NAME 798
#define TCL_FUNC_GET_FILENAME 799
#define TCL_FUNC_INST_SCOPE 800
#define TCL_FUNC_GET_FUNIT_START_AND_END 801
#define TCL_FUNC_COLLECT_UNCOVERED_LINES 802
#define TCL_FUNC_COLLECT_COVERED_LINES 803
#define TCL_FUNC_COLLECT_RACE_LINES 804
#define TCL_FUNC_COLLECT_UNCOVERED_TOGGLES 805
#define TCL_FUNC_COLLECT_COVERED_TOGGLES 806
#define TCL_FUNC_COLLECT_UNCOVERED_MEMORIES 807
#define TCL_FUNC_COLLECT_COVERED_MEMORIES 808
#define TCL_FUNC_GET_TOGGLE_COVERAGE 809
#define TCL_FUNC_GET_MEMORY_COVERAGE 810
#define TCL_FUNC_COLLECT_UNCOVERED_COMBS 811
#define TCL_FUNC_COLLECT_COVERED_COMBS 812
#define TCL_FUNC_GET_COMB_EXPRESSION 813
#define TCL_FUNC_GET_COMB_COVERAGE 814
#define TCL_FUNC_COLLECT_UNCOVERED_FSMS 815
#define TCL_FUNC_COLLECT_COVERED_FSMS 816
#define TCL_FUNC_GET_FSM_COVERAGE 817
#define TCL_FUNC_COLLECT_UNCOVERED_ASSERTIONS 818
#define TCL_FUNC_COLLECT_COVERED_ASSERTIONS 819
#define TCL_FUNC_GET_ASSERT_COVERAGE 820
#define TCL_FUNC_OPEN_CDD 821
#define TCL_FUNC_CLOSE_CDD 822
#define TCL_FUNC_SAVE_CDD 823
#define TCL_FUNC_MERGE_CDD 824
#define TCL_FUNC_GET_LINE_SUMMARY 825
#define TCL_FUNC_GET_TOGGLE_SUMMARY 826
#define TCL_FUNC_GET_MEMORY_SUMMARY 827
#define TCL_FUNC_GET_COMB_SUMMARY 828
#define TCL_FUNC_GET_FSM_SUMMARY 829
#define TCL_FUNC_GET_ASSERT_SUMMARY 830
#define TCL_FUNC_PREPROCESS_VERILOG 831
#define TCL_FUNC_GET_SCORE_PATH 832
#define TCL_FUNC_GET_INCLUDE_PATHNAME 833
#define TCL_FUNC_GET_GENERATION 834
#define TCL_FUNC_SET_LINE_EXCLUDE 835
#define TCL_FUNC_SET_TOGGLE_EXCLUDE 836
#define TCL_FUNC_SET_MEMORY_EXCLUDE 837
#define TCL_FUNC_SET_COMB_EXCLUDE 838
#define TCL_FUNC_FSM_EXCLUDE 839
#define TCL_FUNC_SET_ASSERT_EXCLUDE 840
#define TCL_FUNC_GENERATE_REPORT 841
#define TCL_FUNC_INITIALIZE 842
#define TOGGLE_GET_STATS 843
#define TOGGLE_COLLECT 844
#define TOGGLE_GET_COVERAGE 845
#define TOGGLE_GET_FUNIT_SUMMARY 846
#define TOGGLE_GET_INST_SUMMARY 847
#define TOGGLE_DISPLAY_INSTANCE_SUMMARY 848
#define TOGGLE_INSTANCE_SUMMARY 849
#define TOGGLE_DISPLAY_FUNIT_SUMMARY 850
#define TOGGLE_FUNIT_SUMMARY 851
#define TOGGLE_DISPLAY_VERBOSE 852
#define TOGGLE_INSTANCE_VERBOSE 853
#define TOGGLE_FUNIT_VERBOSE 854
#define TOGGLE_REPORT 855
#define TREE_ADD 856
#define TREE_FIND 857
#define TREE_REMOVE 858
#define TREE_DEALLOC 859
#define CHECK_OPTION_VALUE 860
#define IS_VARIABLE 861
#define IS_FUNC_UNIT 862
#define IS_LEGAL_FILENAME 863
#define GET_BASENAME 864
#define GET_DIRNAME 865
#define GET_ABSOLUTE_PATH 866
#define GET_RELATIVE_PATH 867
#define DIRECTORY_EXISTS 868
#define DIRECTORY_LOAD 869
#define FILE_EXISTS 870
#define UTIL_READLINE 871
#define GET_QUOTED_STRING 872
#define SUBSTITUTE_ENV_VARS 873
#define SCOPE_EXTRACT_FRONT 874
#define SCOPE_EXTRACT_BACK 875
#define SCOPE_EXTRACT_SCOPE 876
#define SCOPE_GEN_PRINTABLE 877
#define SCOPE_COMPARE 878
#define SCOPE_LOCAL 879
#define CONVERT_FILE_TO_MODULE 880
#define GET_NEXT_VFILE 881
#define GEN_SPACE 882
#define GET_FUNIT_TYPE 883
#define CALC_MISS_PERCENT 884
#define READ_COMMAND_FILE 885
#define VCD_PARSE_DEF_IGNORE 886
#define VCD_PARSE_DEF_VAR 887
#define VCD_PARSE_DEF_SCOPE 888
#define VCD_PARSE_DEF 889
#define VCD_PARSE_SIM_VECTOR 890
#define VCD_PARSE_SIM_IGNORE 891
#define VCD_PARSE_SIM 892
#define VCD_PARSE 893
#define VECTOR_INIT 894
#define VECTOR_CREATE 895
#define VECTOR_COPY 896
#define VECTOR_COPY_RANGE 897
#define VECTOR_CLONE 898
#define VECTOR_DB_WRITE 899
#define VECTOR_DB_READ 900
#define VECTOR_DB_MERGE 901
#define VECTOR_MERGE 902
#define VECTOR_GET_EVAL_A 903
#define VECTOR_GET_EVAL_B 904
#define VECTOR_GET_EVAL_C 905
#define VECTOR_GET_EVAL_D 906
#define VECTOR_GET_EVAL_AB_COUNT 907
#define VECTOR_GET_EVAL_ABC_COUNT 908
#define VECTOR_GET_EVAL_ABCD_COUNT 909
#define VECTOR_GET_TOGGLE01_ULONG 910
#define VECTOR_GET_TOGGLE10_ULONG 911
#define VECTOR_DISPLAY_TOGGLE01_ULONG 912
#define VECTOR_DISPLAY_TOGGLE10_ULONG 913
#define VECTOR_TOGGLE_COUNT 914
#define VECTOR_MEM_RW_COUNT 915
#define VECTOR_SET_ASSIGNED 916
#define VECTOR_SET_COVERAGE_AND_ASSIGN 917
#define VECTOR_GET_SIGN_EXTEND_VECTOR_ULONG 918
#define VECTOR_SIGN_EXTEND_ULONG 919
#define VECTOR_LSHIFT_ULONG 920
#define VECTOR_RSHIFT_ULONG 921
#define VECTOR_SET_VALUE 922
#define VECTOR_PART_SELECT_PULL 923
#define VECTOR_PART_SELECT_PUSH 924
#define VECTOR_SET_UNARY_EVALS 925
#define VECTOR_SET_AND_COMB_EVALS 926
#define VECTOR_SET_OR_COMB_EVALS 927
#define VECTOR_SET_OTHER_COMB_EVALS 928
#define VECTOR_IS_UKNOWN 929
#define VECTOR_IS_NOT_ZERO 930
#define VECTOR_SET_TO_X 931
#define VECTOR_TO_INT 932
#define VECTOR_TO_UINT64 933
#define VECTOR_TO_SIM_TIME 934
#define VECTOR_FROM_INT 935
#define VECTOR_FROM_UINT64 936
#define VECTOR_SET_STATIC 937
#define VECTOR_TO_STRING 938
#define VECTOR_FROM_STRING 939
#define VECTOR_VCD_ASSIGN 940
#define VECTOR_BITWISE_AND_OP 941
#define VECTOR_BITWISE_NAND_OP 942
#define VECTOR_BITWISE_OR_OP 943
#define VECTOR_BITWISE_NOR_OP 944
#define VECTOR_BITWISE_XOR_OP 945
#define VECTOR_BITWISE_NXOR_OP 946
#define VECTOR_OP_LT 947
#define VECTOR_OP_LE 948
#define VECTOR_OP_GT 949
#define VECTOR_OP_GE 950
#define VECTOR_OP_EQ 951
#define VECTOR_CEQ_ULONG 952
#define VECTOR_OP_CEQ 953
#define VECTOR_OP_CXEQ 954
#define VECTOR_OP_CZEQ 955
#define VECTOR_OP_NE 956
#define VECTOR_OP_CNE 957
#define VECTOR_OP_LOR 958
#define VECTOR_OP_LAND 959
#define VECTOR_OP_LSHIFT 960
#define VECTOR_OP_RSHIFT 961
#define VECTOR_OP_ARSHIFT 962
#define VECTOR_OP_ADD 963
#define VECTOR_OP_NEGATE 964
#define VECTOR_OP_SUBTRACT 965
#define VECTOR_OP_MULTIPLY 966
#define VECTOR_OP_DIVIDE 967
#define VECTOR_OP_MODULUS 968
#define VECTOR_OP_INC 969
#define VECTOR_OP_DEC 970
#define VECTOR_UNARY_INV 971
#define VECTOR_UNARY_AND 972
#define VECTOR_UNARY_NAND 973
#define VECTOR_UNARY_OR 974
#define VECTOR_UNARY_NOR 975
#define VECTOR_UNARY_XOR 976
#define VECTOR_UNARY_NXOR 977
#define VECTOR_UNARY_NOT 978
#define VECTOR_OP_EXPAND 979
#define VECTOR_OP_LIST 980
#define VECTOR_DEALLOC_VALUE 981
#define VECTOR_DEALLOC 982
#define SYM_VALUE_STORE 983
#define ADD_SYM_VALUES_TO_SIM 984
#define COVERED_VALUE_CHANGE 985
#define COVERED_END_OF_SIM 986
#define COVERED_CB_ERROR_HANDLER 987
#define GEN_NEXT_SYMBOL 988
#define COVERED_CREATE_VALUE_CHANGE_CB 989
#define COVERED_PARSE_TASK_FUNC 990
#define COVERED_PARSE_SIGNALS 991
#define COVERED_PARSE_INSTANCE 992
#define COVERED_SIM_CALLTF 993
#define COVERED_REGISTER 994
#define VSIGNAL_INIT 995
#define VSIGNAL_CREATE 996
#define VSIGNAL_CREATE_VEC 997
#define VSIGNAL_DUPLICATE 998
#define VSIGNAL_DB_WRITE 999
#define VSIGNAL_DB_READ 1000
#define VSIGNAL_DB_MERGE 1001
#define VSIGNAL_MERGE 1002
#define VSIGNAL_PROPAGATE 1003
#define VSIGNAL_VCD_ASSIGN 1004
#define VSIGNAL_ADD_EXPRESSION 1005
#define VSIGNAL_FROM_STRING 1006
#define VSIGNAL_CALC_WIDTH_FOR_EXPR 1007
#define VSIGNAL_CALC_LSB_FOR_EXPR 1008
#define VSIGNAL_DEALLOC 1009

extern profiler profiles[NUM_PROFILES];
#endif

extern unsigned int profile_index;

#endif

