#ifndef __GENPROF_H__
#define __GENPROF_H__

/*
 Copyright (c) 2006-2009 Trevor Williams

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

#define NUM_PROFILES 1053

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
#define DB_MERGE_INSTANCE_TREES 91
#define DB_SCALE_TO_PRECISION 92
#define DB_CREATE_UNNAMED_SCOPE 93
#define DB_IS_UNNAMED_SCOPE 94
#define DB_SET_TIMESCALE 95
#define DB_GET_CURR_FUNIT 96
#define DB_GET_EXCLUSION_ID_SIZE 97
#define DB_GEN_EXCLUSION_ID 98
#define DB_ADD_FILE_VERSION 99
#define DB_OUTPUT_DUMPVARS 100
#define DB_ADD_INSTANCE 101
#define DB_ADD_MODULE 102
#define DB_END_MODULE 103
#define DB_ADD_FUNCTION_TASK_NAMEDBLOCK 104
#define DB_END_FUNCTION_TASK_NAMEDBLOCK 105
#define DB_ADD_DECLARED_PARAM 106
#define DB_ADD_OVERRIDE_PARAM 107
#define DB_ADD_VECTOR_PARAM 108
#define DB_ADD_DEFPARAM 109
#define DB_ADD_SIGNAL 110
#define DB_ADD_ENUM 111
#define DB_END_ENUM_LIST 112
#define DB_ADD_TYPEDEF 113
#define DB_FIND_SIGNAL 114
#define DB_ADD_GEN_ITEM_BLOCK 115
#define DB_FIND_GEN_ITEM 116
#define DB_FIND_TYPEDEF 117
#define DB_GET_CURR_GEN_BLOCK 118
#define DB_CURR_SIGNAL_COUNT 119
#define DB_CREATE_EXPRESSION 120
#define DB_BIND_EXPR_TREE 121
#define DB_CREATE_EXPR_FROM_STATIC 122
#define DB_ADD_EXPRESSION 123
#define DB_CREATE_SENSITIVITY_LIST 124
#define DB_PARALLELIZE_STATEMENT 125
#define DB_CREATE_STATEMENT 126
#define DB_ADD_STATEMENT 127
#define DB_REMOVE_STATEMENT_FROM_CURRENT_FUNIT 128
#define DB_REMOVE_STATEMENT 129
#define DB_CONNECT_STATEMENT_TRUE 130
#define DB_CONNECT_STATEMENT_FALSE 131
#define DB_GEN_ITEM_CONNECT_TRUE 132
#define DB_GEN_ITEM_CONNECT_FALSE 133
#define DB_GEN_ITEM_CONNECT 134
#define DB_STATEMENT_CONNECT 135
#define DB_CREATE_ATTR_PARAM 136
#define DB_PARSE_ATTRIBUTE 137
#define DB_REMOVE_STMT_BLKS_CALLING_STATEMENT 138
#define DB_GEN_CURR_INST_SCOPE 139
#define DB_SYNC_CURR_INSTANCE 140
#define DB_SET_VCD_SCOPE 141
#define DB_VCD_UPSCOPE 142
#define DB_ASSIGN_SYMBOL 143
#define DB_SET_SYMBOL_CHAR 144
#define DB_SET_SYMBOL_STRING 145
#define DB_DO_TIMESTEP 146
#define ENUMERATE_ADD_ITEM 147
#define ENUMERATE_END_LIST 148
#define ENUMERATE_RESOLVE 149
#define ENUMERATE_DEALLOC 150
#define ENUMERATE_DEALLOC_LIST 151
#define EXCLUDE_EXPR_ASSIGN_AND_RECALC 152
#define EXCLUDE_SIG_ASSIGN_AND_RECALC 153
#define EXCLUDE_ARC_ASSIGN_AND_RECALC 154
#define EXCLUDE_ADD_EXCLUDE_REASON 155
#define EXCLUDE_REMOVE_EXCLUDE_REASON 156
#define EXCLUDE_IS_LINE_EXCLUDED 157
#define EXCLUDE_SET_LINE_EXCLUDE 158
#define EXCLUDE_IS_TOGGLE_EXCLUDED 159
#define EXCLUDE_SET_TOGGLE_EXCLUDE 160
#define EXCLUDE_IS_COMB_EXCLUDED 161
#define EXCLUDE_SET_COMB_EXCLUDE 162
#define EXCLUDE_IS_FSM_EXCLUDED 163
#define EXCLUDE_SET_FSM_EXCLUDE 164
#define EXCLUDE_IS_ASSERT_EXCLUDED 165
#define EXCLUDE_SET_ASSERT_EXCLUDE 166
#define EXCLUDE_FIND_EXCLUDE_REASON 167
#define EXCLUDE_DB_WRITE 168
#define EXCLUDE_DB_READ 169
#define EXCLUDE_RESOLVE_REASON 170
#define EXCLUDE_DB_MERGE 171
#define EXCLUDE_MERGE 172
#define EXCLUDE_FIND_SIGNAL 173
#define EXCLUDE_FIND_EXPRESSION 174
#define EXCLUDE_FIND_FSM_ARC 175
#define EXCLUDE_FORMAT_REASON 176
#define EXCLUDED_GET_MESSAGE 177
#define EXCLUDE_HANDLE_EXCLUDE_REASON 178
#define EXCLUDE_PRINT_EXCLUSION 179
#define EXCLUDE_LINE_FROM_ID 180
#define EXCLUDE_TOGGLE_FROM_ID 181
#define EXCLUDE_MEMORY_FROM_ID 182
#define EXCLUDE_EXPR_FROM_ID 183
#define EXCLUDE_FSM_FROM_ID 184
#define EXCLUDE_ASSERT_FROM_ID 185
#define EXCLUDE_APPLY_EXCLUSIONS 186
#define COMMAND_EXCLUDE 187
#define EXPRESSION_CREATE_TMP_VECS 188
#define EXPRESSION_CREATE_VALUE 189
#define EXPRESSION_CREATE 190
#define EXPRESSION_SET_VALUE 191
#define EXPRESSION_SET_SIGNED 192
#define EXPRESSION_RESIZE 193
#define EXPRESSION_GET_ID 194
#define EXPRESSION_GET_FIRST_LINE_EXPR 195
#define EXPRESSION_GET_LAST_LINE_EXPR 196
#define EXPRESSION_GET_CURR_DIMENSION 197
#define EXPRESSION_FIND_RHS_SIGS 198
#define EXPRESSION_FIND_PARAMS 199
#define EXPRESSION_FIND_ULINE_ID 200
#define EXPRESSION_FIND_EXPR 201
#define EXPRESSION_CONTAINS_EXPR_CALLING_STMT 202
#define EXPRESSION_GET_ROOT_STATEMENT 203
#define EXPRESSION_ASSIGN_EXPR_IDS 204
#define EXPRESSION_DB_WRITE 205
#define EXPRESSION_DB_WRITE_TREE 206
#define EXPRESSION_DB_READ 207
#define EXPRESSION_DB_MERGE 208
#define EXPRESSION_MERGE 209
#define EXPRESSION_STRING_OP 210
#define EXPRESSION_STRING 211
#define EXPRESSION_OP_FUNC__XOR 212
#define EXPRESSION_OP_FUNC__XOR_A 213
#define EXPRESSION_OP_FUNC__MULTIPLY 214
#define EXPRESSION_OP_FUNC__MULTIPLY_A 215
#define EXPRESSION_OP_FUNC__DIVIDE 216
#define EXPRESSION_OP_FUNC__DIVIDE_A 217
#define EXPRESSION_OP_FUNC__MOD 218
#define EXPRESSION_OP_FUNC__MOD_A 219
#define EXPRESSION_OP_FUNC__ADD 220
#define EXPRESSION_OP_FUNC__ADD_A 221
#define EXPRESSION_OP_FUNC__SUBTRACT 222
#define EXPRESSION_OP_FUNC__SUB_A 223
#define EXPRESSION_OP_FUNC__AND 224
#define EXPRESSION_OP_FUNC__AND_A 225
#define EXPRESSION_OP_FUNC__OR 226
#define EXPRESSION_OP_FUNC__OR_A 227
#define EXPRESSION_OP_FUNC__NAND 228
#define EXPRESSION_OP_FUNC__NOR 229
#define EXPRESSION_OP_FUNC__NXOR 230
#define EXPRESSION_OP_FUNC__LT 231
#define EXPRESSION_OP_FUNC__GT 232
#define EXPRESSION_OP_FUNC__LSHIFT 233
#define EXPRESSION_OP_FUNC__LSHIFT_A 234
#define EXPRESSION_OP_FUNC__RSHIFT 235
#define EXPRESSION_OP_FUNC__RSHIFT_A 236
#define EXPRESSION_OP_FUNC__ARSHIFT 237
#define EXPRESSION_OP_FUNC__ARSHIFT_A 238
#define EXPRESSION_OP_FUNC__TIME 239
#define EXPRESSION_OP_FUNC__RANDOM 240
#define EXPRESSION_OP_FUNC__SASSIGN 241
#define EXPRESSION_OP_FUNC__SRANDOM 242
#define EXPRESSION_OP_FUNC__URANDOM 243
#define EXPRESSION_OP_FUNC__URANDOM_RANGE 244
#define EXPRESSION_OP_FUNC__REALTOBITS 245
#define EXPRESSION_OP_FUNC__BITSTOREAL 246
#define EXPRESSION_OP_FUNC__SHORTREALTOBITS 247
#define EXPRESSION_OP_FUNC__BITSTOSHORTREAL 248
#define EXPRESSION_OP_FUNC__ITOR 249
#define EXPRESSION_OP_FUNC__RTOI 250
#define EXPRESSION_OP_FUNC__TEST_PLUSARGS 251
#define EXPRESSION_OP_FUNC__VALUE_PLUSARGS 252
#define EXPRESSION_OP_FUNC__SIGNED 253
#define EXPRESSION_OP_FUNC__UNSIGNED 254
#define EXPRESSION_OP_FUNC__EQ 255
#define EXPRESSION_OP_FUNC__CEQ 256
#define EXPRESSION_OP_FUNC__LE 257
#define EXPRESSION_OP_FUNC__GE 258
#define EXPRESSION_OP_FUNC__NE 259
#define EXPRESSION_OP_FUNC__CNE 260
#define EXPRESSION_OP_FUNC__LOR 261
#define EXPRESSION_OP_FUNC__LAND 262
#define EXPRESSION_OP_FUNC__COND 263
#define EXPRESSION_OP_FUNC__COND_SEL 264
#define EXPRESSION_OP_FUNC__UINV 265
#define EXPRESSION_OP_FUNC__UAND 266
#define EXPRESSION_OP_FUNC__UNOT 267
#define EXPRESSION_OP_FUNC__UOR 268
#define EXPRESSION_OP_FUNC__UXOR 269
#define EXPRESSION_OP_FUNC__UNAND 270
#define EXPRESSION_OP_FUNC__UNOR 271
#define EXPRESSION_OP_FUNC__UNXOR 272
#define EXPRESSION_OP_FUNC__NULL 273
#define EXPRESSION_OP_FUNC__SIG 274
#define EXPRESSION_OP_FUNC__SBIT 275
#define EXPRESSION_OP_FUNC__MBIT 276
#define EXPRESSION_OP_FUNC__EXPAND 277
#define EXPRESSION_OP_FUNC__LIST 278
#define EXPRESSION_OP_FUNC__CONCAT 279
#define EXPRESSION_OP_FUNC__PEDGE 280
#define EXPRESSION_OP_FUNC__NEDGE 281
#define EXPRESSION_OP_FUNC__AEDGE 282
#define EXPRESSION_OP_FUNC__EOR 283
#define EXPRESSION_OP_FUNC__SLIST 284
#define EXPRESSION_OP_FUNC__DELAY 285
#define EXPRESSION_OP_FUNC__TRIGGER 286
#define EXPRESSION_OP_FUNC__CASE 287
#define EXPRESSION_OP_FUNC__CASEX 288
#define EXPRESSION_OP_FUNC__CASEZ 289
#define EXPRESSION_OP_FUNC__DEFAULT 290
#define EXPRESSION_OP_FUNC__BASSIGN 291
#define EXPRESSION_OP_FUNC__FUNC_CALL 292
#define EXPRESSION_OP_FUNC__TASK_CALL 293
#define EXPRESSION_OP_FUNC__NB_CALL 294
#define EXPRESSION_OP_FUNC__FORK 295
#define EXPRESSION_OP_FUNC__JOIN 296
#define EXPRESSION_OP_FUNC__DISABLE 297
#define EXPRESSION_OP_FUNC__REPEAT 298
#define EXPRESSION_OP_FUNC__EXPONENT 299
#define EXPRESSION_OP_FUNC__PASSIGN 300
#define EXPRESSION_OP_FUNC__MBIT_POS 301
#define EXPRESSION_OP_FUNC__MBIT_NEG 302
#define EXPRESSION_OP_FUNC__NEGATE 303
#define EXPRESSION_OP_FUNC__IINC 304
#define EXPRESSION_OP_FUNC__PINC 305
#define EXPRESSION_OP_FUNC__IDEC 306
#define EXPRESSION_OP_FUNC__PDEC 307
#define EXPRESSION_OP_FUNC__DLY_ASSIGN 308
#define EXPRESSION_OP_FUNC__DLY_OP 309
#define EXPRESSION_OP_FUNC__REPEAT_DLY 310
#define EXPRESSION_OP_FUNC__DIM 311
#define EXPRESSION_OP_FUNC__WAIT 312
#define EXPRESSION_OP_FUNC__FINISH 313
#define EXPRESSION_OP_FUNC__STOP 314
#define EXPRESSION_OPERATE 315
#define EXPRESSION_OPERATE_RECURSIVELY 316
#define EXPRESSION_IS_STATIC_ONLY_HELPER 317
#define EXPRESSION_IS_ASSIGNED 318
#define EXPRESSION_IS_BIT_SELECT 319
#define EXPRESSION_IS_LAST_SELECT 320
#define EXPRESSION_IS_IN_RASSIGN 321
#define EXPRESSION_SET_ASSIGNED 322
#define EXPRESSION_SET_CHANGED 323
#define EXPRESSION_ASSIGN 324
#define EXPRESSION_DEALLOC 325
#define FSM_CREATE 326
#define FSM_ADD_ARC 327
#define FSM_CREATE_TABLES 328
#define FSM_DB_WRITE 329
#define FSM_DB_READ 330
#define FSM_DB_MERGE 331
#define FSM_MERGE 332
#define FSM_TABLE_SET 333
#define FSM_GET_STATS 334
#define FSM_GET_FUNIT_SUMMARY 335
#define FSM_GET_INST_SUMMARY 336
#define FSM_GATHER_SIGNALS 337
#define FSM_COLLECT 338
#define FSM_GET_COVERAGE 339
#define FSM_DISPLAY_INSTANCE_SUMMARY 340
#define FSM_INSTANCE_SUMMARY 341
#define FSM_DISPLAY_FUNIT_SUMMARY 342
#define FSM_FUNIT_SUMMARY 343
#define FSM_DISPLAY_STATE_VERBOSE 344
#define FSM_DISPLAY_ARC_VERBOSE 345
#define FSM_DISPLAY_VERBOSE 346
#define FSM_INSTANCE_VERBOSE 347
#define FSM_FUNIT_VERBOSE 348
#define FSM_REPORT 349
#define FSM_DEALLOC 350
#define FSM_ARG_PARSE_STATE 351
#define FSM_ARG_PARSE 352
#define FSM_ARG_PARSE_VALUE 353
#define FSM_ARG_PARSE_TRANS 354
#define FSM_ARG_PARSE_ATTR 355
#define FSM_VAR_ADD 356
#define FSM_VAR_IS_OUTPUT_STATE 357
#define FSM_VAR_BIND_EXPR 358
#define FSM_VAR_ADD_EXPR 359
#define FSM_VAR_BIND_STMT 360
#define FSM_VAR_BIND_ADD 361
#define FSM_VAR_STMT_ADD 362
#define FSM_VAR_BIND 363
#define FSM_VAR_DEALLOC 364
#define FSM_VAR_REMOVE 365
#define FSM_VAR_CLEANUP 366
#define FUNC_ITER_DISPLAY 367
#define FUNC_ITER_SORT 368
#define FUNC_ITER_COUNT_STMT_ITERS 369
#define FUNC_ITER_ADD_STMT_ITERS 370
#define FUNC_ITER_ADD_SIG_LINKS 371
#define FUNC_ITER_INIT 372
#define FUNC_ITER_GET_NEXT_STATEMENT 373
#define FUNC_ITER_GET_NEXT_SIGNAL 374
#define FUNC_ITER_DEALLOC 375
#define FUNIT_INIT 376
#define FUNIT_CREATE 377
#define FUNIT_GET_CURR_MODULE 378
#define FUNIT_GET_CURR_MODULE_SAFE 379
#define FUNIT_GET_CURR_FUNCTION 380
#define FUNIT_GET_CURR_TASK 381
#define FUNIT_GET_PORT_COUNT 382
#define FUNIT_FIND_PARAM 383
#define FUNIT_FIND_SIGNAL 384
#define FUNIT_REMOVE_STMT_BLKS_CALLING_STMT 385
#define FUNIT_GEN_TASK_FUNCTION_NAMEDBLOCK_NAME 386
#define FUNIT_SIZE_ELEMENTS 387
#define FUNIT_DB_WRITE 388
#define FUNIT_DB_READ 389
#define FUNIT_VERSION_DB_READ 390
#define FUNIT_DB_MERGE 391
#define FUNIT_MERGE 392
#define FUNIT_FLATTEN_NAME 393
#define FUNIT_FIND_BY_ID 394
#define FUNIT_IS_TOP_MODULE 395
#define FUNIT_IS_UNNAMED 396
#define FUNIT_IS_UNNAMED_CHILD_OF 397
#define FUNIT_IS_CHILD_OF 398
#define FUNIT_DISPLAY_SIGNALS 399
#define FUNIT_DISPLAY_EXPRESSIONS 400
#define STATEMENT_ADD_THREAD 401
#define FUNIT_PUSH_THREADS 402
#define STATEMENT_DELETE_THREAD 403
#define FUNIT_OUTPUT_DUMPVARS 404
#define FUNIT_CLEAN 405
#define FUNIT_DEALLOC 406
#define GEN_ITEM_STRINGIFY 407
#define GEN_ITEM_DISPLAY 408
#define GEN_ITEM_DISPLAY_BLOCK_HELPER 409
#define GEN_ITEM_DISPLAY_BLOCK 410
#define GEN_ITEM_COMPARE 411
#define GEN_ITEM_FIND 412
#define GEN_ITEM_REMOVE_IF_CONTAINS_EXPR_CALLING_STMT 413
#define GEN_ITEM_GET_GENVAR 414
#define GEN_ITEM_VARNAME_CONTAINS_GENVAR 415
#define GEN_ITEM_CALC_SIGNAL_NAME 416
#define GEN_ITEM_CREATE_EXPR 417
#define GEN_ITEM_CREATE_SIG 418
#define GEN_ITEM_CREATE_STMT 419
#define GEN_ITEM_CREATE_INST 420
#define GEN_ITEM_CREATE_TFN 421
#define GEN_ITEM_CREATE_BIND 422
#define GEN_ITEM_RESIZE_STMTS_AND_SIGS 423
#define GEN_ITEM_ASSIGN_IDS 424
#define GEN_ITEM_DB_WRITE 425
#define GEN_ITEM_DB_WRITE_EXPR_TREE 426
#define GEN_ITEM_CONNECT 427
#define GEN_ITEM_RESOLVE 428
#define GEN_ITEM_BIND 429
#define GENERATE_RESOLVE 430
#define GENERATE_REMOVE_STMT_HELPER 431
#define GENERATE_REMOVE_STMT 432
#define GEN_ITEM_DEALLOC 433
#define SCORE_ADD_ARGS 434
#define INFO_SET_VECTOR_ELEM_SIZE 435
#define INFO_DB_WRITE 436
#define INFO_DB_READ 437
#define ARGS_DB_READ 438
#define MESSAGE_DB_READ 439
#define MERGED_CDD_DB_READ 440
#define INFO_DEALLOC 441
#define INSTANCE_DISPLAY_TREE_HELPER 442
#define INSTANCE_DISPLAY_TREE 443
#define INSTANCE_CREATE 444
#define INSTANCE_GEN_SCOPE 445
#define INSTANCE_COMPARE 446
#define INSTANCE_FIND_SCOPE 447
#define INSTANCE_FIND_BY_FUNIT 448
#define INSTANCE_FIND_BY_FUNIT_NAME_IF_ONE_HELPER 449
#define INSTANCE_FIND_BY_FUNIT_NAME_IF_ONE 450
#define INSTANCE_FIND_SIGNAL_BY_EXCLUSION_ID 451
#define INSTANCE_FIND_EXPRESSION_BY_EXCLUSION_ID 452
#define INSTANCE_FIND_FSM_ARC_INDEX_BY_EXCLUSION_ID 453
#define INSTANCE_ADD_CHILD 454
#define INSTANCE_COPY 455
#define INSTANCE_PARSE_ADD 456
#define INSTANCE_RESOLVE_INST 457
#define INSTANCE_RESOLVE_HELPER 458
#define INSTANCE_RESOLVE 459
#define INSTANCE_READ_ADD 460
#define INSTANCE_MERGE 461
#define INSTANCE_GET_LEADING_HIERARCHY 462
#define INSTANCE_MARK_LHIER_DIFFS 463
#define INSTANCE_MERGE_TWO_TREES 464
#define INSTANCE_DB_WRITE 465
#define INSTANCE_ONLY_DB_READ 466
#define INSTANCE_ONLY_DB_MERGE 467
#define INSTANCE_REMOVE_STMT_BLKS_CALLING_STMT 468
#define INSTANCE_REMOVE_PARMS_WITH_EXPR 469
#define INSTANCE_DEALLOC_SINGLE 470
#define INSTANCE_OUTPUT_DUMPVARS 471
#define INSTANCE_DEALLOC_TREE 472
#define INSTANCE_DEALLOC 473
#define STMT_ITER_RESET 474
#define STMT_ITER_COPY 475
#define STMT_ITER_NEXT 476
#define STMT_ITER_REVERSE 477
#define STMT_ITER_FIND_HEAD 478
#define STMT_ITER_GET_NEXT_IN_ORDER 479
#define STMT_ITER_GET_LINE_BEFORE 480
#define LEXER_KEYWORD_1995_CODE 481
#define LEXER_KEYWORD_2001_CODE 482
#define LEXER_KEYWORD_SV_CODE 483
#define LEXER_KEYWORD_SYS_1995_CODE 484
#define LEXER_KEYWORD_SYS_2001_CODE 485
#define LEXER_KEYWORD_SYS_SV_CODE 486
#define LEXER_CSTRING_A 487
#define LEXER_KEYWORD_A 488
#define LEXER_ESCAPED_NAME 489
#define LEXER_SYSTEM_CALL 490
#define LINE_DIRECTIVE 491
#define LINE_DIRECTIVE2 492
#define PROCESS_TIMESCALE_TOKEN 493
#define PROCESS_TIMESCALE 494
#define LEXER_YYWRAP 495
#define RESET_LEXER 496
#define CHECK_FOR_PRAGMA 497
#define LINE_GET_STATS 498
#define LINE_COLLECT 499
#define LINE_GET_FUNIT_SUMMARY 500
#define LINE_GET_INST_SUMMARY 501
#define LINE_DISPLAY_INSTANCE_SUMMARY 502
#define LINE_INSTANCE_SUMMARY 503
#define LINE_DISPLAY_FUNIT_SUMMARY 504
#define LINE_FUNIT_SUMMARY 505
#define LINE_DISPLAY_VERBOSE 506
#define LINE_INSTANCE_VERBOSE 507
#define LINE_FUNIT_VERBOSE 508
#define LINE_REPORT 509
#define STR_LINK_ADD 510
#define STMT_LINK_ADD_HEAD 511
#define STMT_LINK_ADD_TAIL 512
#define STMT_LINK_MERGE 513
#define EXP_LINK_ADD 514
#define SIG_LINK_ADD 515
#define FSM_LINK_ADD 516
#define FUNIT_LINK_ADD 517
#define GITEM_LINK_ADD 518
#define INST_LINK_ADD 519
#define STR_LINK_FIND 520
#define STMT_LINK_FIND 521
#define EXP_LINK_FIND 522
#define SIG_LINK_FIND 523
#define FSM_LINK_FIND 524
#define FUNIT_LINK_FIND 525
#define GITEM_LINK_FIND 526
#define INST_LINK_FIND_BY_SCOPE 527
#define INST_LINK_FIND_BY_FUNIT 528
#define STR_LINK_REMOVE 529
#define EXP_LINK_REMOVE 530
#define GITEM_LINK_REMOVE 531
#define FUNIT_LINK_REMOVE 532
#define STR_LINK_DELETE_LIST 533
#define STMT_LINK_UNLINK 534
#define STMT_LINK_DELETE_LIST 535
#define EXP_LINK_DELETE_LIST 536
#define SIG_LINK_DELETE_LIST 537
#define FSM_LINK_DELETE_LIST 538
#define FUNIT_LINK_DELETE_LIST 539
#define GITEM_LINK_DELETE_LIST 540
#define INST_LINK_DELETE_LIST 541
#define VCDID 542
#define VCD_CALLBACK 543
#define LXT_PARSE 544
#define LXT2_RD_EXPAND_INTEGER_TO_BITS 545
#define LXT2_RD_EXPAND_BITS_TO_INTEGER 546
#define LXT2_RD_ITER_RADIX 547
#define LXT2_RD_ITER_RADIX0 548
#define LXT2_RD_BUILD_RADIX 549
#define LXT2_RD_REGENERATE_PROCESS_MASK 550
#define LXT2_RD_PROCESS_BLOCK 551
#define LXT2_RD_INIT 552
#define LXT2_RD_CLOSE 553
#define LXT2_RD_GET_FACNAME 554
#define LXT2_RD_ITER_BLOCKS 555
#define LXT2_RD_LIMIT_TIME_RANGE 556
#define LXT2_RD_UNLIMIT_TIME_RANGE 557
#define MEMORY_GET_STAT 558
#define MEMORY_GET_STATS 559
#define MEMORY_GET_FUNIT_SUMMARY 560
#define MEMORY_GET_INST_SUMMARY 561
#define MEMORY_CREATE_PDIM_BIT_ARRAY 562
#define MEMORY_GET_MEM_COVERAGE 563
#define MEMORY_GET_COVERAGE 564
#define MEMORY_COLLECT 565
#define MEMORY_DISPLAY_TOGGLE_INSTANCE_SUMMARY 566
#define MEMORY_TOGGLE_INSTANCE_SUMMARY 567
#define MEMORY_DISPLAY_AE_INSTANCE_SUMMARY 568
#define MEMORY_AE_INSTANCE_SUMMARY 569
#define MEMORY_DISPLAY_TOGGLE_FUNIT_SUMMARY 570
#define MEMORY_TOGGLE_FUNIT_SUMMARY 571
#define MEMORY_DISPLAY_AE_FUNIT_SUMMARY 572
#define MEMORY_AE_FUNIT_SUMMARY 573
#define MEMORY_DISPLAY_MEMORY 574
#define MEMORY_DISPLAY_VERBOSE 575
#define MEMORY_INSTANCE_VERBOSE 576
#define MEMORY_FUNIT_VERBOSE 577
#define MEMORY_REPORT 578
#define COMMAND_MERGE 579
#define OBFUSCATE_SET_MODE 580
#define OBFUSCATE_NAME 581
#define OBFUSCATE_DEALLOC 582
#define OVL_IS_ASSERTION_NAME 583
#define OVL_IS_ASSERTION_MODULE 584
#define OVL_IS_COVERAGE_POINT 585
#define OVL_ADD_ASSERTIONS_TO_NO_SCORE_LIST 586
#define OVL_GET_FUNIT_STATS 587
#define OVL_GET_COVERAGE_POINT 588
#define OVL_DISPLAY_VERBOSE 589
#define OVL_COLLECT 590
#define OVL_GET_COVERAGE 591
#define MOD_PARM_FIND 592
#define MOD_PARM_FIND_EXPR_AND_REMOVE 593
#define MOD_PARM_ADD 594
#define INST_PARM_FIND 595
#define INST_PARM_ADD 596
#define INST_PARM_ADD_GENVAR 597
#define INST_PARM_BIND 598
#define DEFPARAM_ADD 599
#define DEFPARAM_DEALLOC 600
#define PARAM_FIND_AND_SET_EXPR_VALUE 601
#define PARAM_SET_SIG_SIZE 602
#define PARAM_SIZE_FUNCTION 603
#define PARAM_EXPR_EVAL 604
#define PARAM_HAS_OVERRIDE 605
#define PARAM_HAS_DEFPARAM 606
#define PARAM_RESOLVE_DECLARED 607
#define PARAM_RESOLVE_OVERRIDE 608
#define PARAM_RESOLVE 609
#define PARAM_DB_WRITE 610
#define MOD_PARM_DEALLOC 611
#define INST_PARM_DEALLOC 612
#define PARSE_READLINE 613
#define PARSE_DESIGN 614
#define PARSE_AND_SCORE_DUMPFILE 615
#define PARSER_PORT_DECLARATION_A 616
#define PARSER_PORT_DECLARATION_B 617
#define PARSER_PORT_DECLARATION_C 618
#define PARSER_STATIC_EXPR_PRIMARY_A 619
#define PARSER_STATIC_EXPR_PRIMARY_B 620
#define PARSER_EXPRESSION_LIST_A 621
#define PARSER_EXPRESSION_LIST_B 622
#define PARSER_EXPRESSION_LIST_C 623
#define PARSER_EXPRESSION_LIST_D 624
#define PARSER_IDENTIFIER_A 625
#define PARSER_GENERATE_CASE_ITEM_A 626
#define PARSER_GENERATE_CASE_ITEM_B 627
#define PARSER_GENERATE_CASE_ITEM_C 628
#define PARSER_STATEMENT_BEGIN_A 629
#define PARSER_STATEMENT_FORK_A 630
#define PARSER_STATEMENT_FOR_A 631
#define PARSER_CASE_ITEM_A 632
#define PARSER_CASE_ITEM_B 633
#define PARSER_CASE_ITEM_C 634
#define PARSER_DELAY_VALUE_A 635
#define PARSER_DELAY_VALUE_B 636
#define PARSER_PARAMETER_VALUE_BYNAME_A 637
#define PARSER_GATE_INSTANCE_A 638
#define PARSER_GATE_INSTANCE_B 639
#define PARSER_GATE_INSTANCE_C 640
#define PARSER_GATE_INSTANCE_D 641
#define PARSER_LIST_OF_NAMES_A 642
#define PARSER_LIST_OF_NAMES_B 643
#define VLERROR 644
#define VLWARN 645
#define PARSER_DEALLOC_SIG_RANGE 646
#define PARSER_COPY_CURR_RANGE 647
#define PARSER_COPY_RANGE_TO_CURR_RANGE 648
#define PARSER_EXPLICITLY_SET_CURR_RANGE 649
#define PARSER_IMPLICITLY_SET_CURR_RANGE 650
#define PARSER_CHECK_GENERATION 651
#define PARSER_HANDLE_CASE_STATEMENT 652
#define PARSER_HANDLE_CASE_STATEMENT_LIST 653
#define PARSER_HANDLE_GENERATE_CASE_STATEMENT 654
#define PARSER_HANDLE_GENERATE_CASE_STATEMENT_LIST 655
#define PERF_GEN_STATS 656
#define PERF_OUTPUT_MOD_STATS 657
#define PERF_OUTPUT_INST_REPORT_HELPER 658
#define PERF_OUTPUT_INST_REPORT 659
#define DEF_LOOKUP 660
#define IS_DEFINED 661
#define DEF_MATCH 662
#define DEF_START 663
#define DEFINE_MACRO 664
#define DO_DEFINE 665
#define DEF_IS_DONE 666
#define DEF_FINISH 667
#define DEF_UNDEFINE 668
#define INCLUDE_FILENAME 669
#define DO_INCLUDE 670
#define YYWRAP 671
#define RESET_PPLEXER 672
#define RACE_BLK_CREATE 673
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT_HELPER 674
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT 675
#define RACE_GET_HEAD_STATEMENT 676
#define RACE_FIND_HEAD_STATEMENT 677
#define RACE_CALC_STMT_BLK_TYPE 678
#define RACE_CALC_EXPR_ASSIGNMENT 679
#define RACE_CALC_ASSIGNMENTS 680
#define RACE_HANDLE_RACE_CONDITION 681
#define RACE_CHECK_ASSIGNMENT_TYPES 682
#define RACE_CHECK_ONE_BLOCK_ASSIGNMENT 683
#define RACE_CHECK_RACE_COUNT 684
#define RACE_CHECK_MODULES 685
#define RACE_DB_WRITE 686
#define RACE_DB_READ 687
#define RACE_GET_STATS 688
#define RACE_REPORT_SUMMARY 689
#define RACE_REPORT_VERBOSE 690
#define RACE_REPORT 691
#define RACE_COLLECT_LINES 692
#define RACE_BLK_DELETE_LIST 693
#define RANK_CREATE_COMP_CDD_COV 694
#define RANK_DEALLOC_COMP_CDD_COV 695
#define RANK_CHECK_INDEX 696
#define RANK_GATHER_SIGNAL_COV 697
#define RANK_GATHER_COMB_COV 698
#define RANK_GATHER_EXPRESSION_COV 699
#define RANK_GATHER_FSM_COV 700
#define RANK_CALC_NUM_CPS 701
#define RANK_GATHER_COMP_CDD_COV 702
#define RANK_READ_CDD 703
#define RANK_SELECTED_CDD_COV 704
#define RANK_PERFORM_WEIGHTED_SELECTION 705
#define RANK_PERFORM_GREEDY_SORT 706
#define RANK_COUNT_CPS 707
#define RANK_PERFORM 708
#define RANK_OUTPUT 709
#define COMMAND_RANK 710
#define REENTRANT_COUNT_AFU_BITS 711
#define REENTRANT_STORE_DATA_BITS 712
#define REENTRANT_RESTORE_DATA_BITS 713
#define REENTRANT_CREATE 714
#define REENTRANT_DEALLOC 715
#define REPORT_PARSE_METRICS 716
#define REPORT_PARSE_ARGS 717
#define REPORT_GATHER_INSTANCE_STATS 718
#define REPORT_GATHER_FUNIT_STATS 719
#define REPORT_PRINT_HEADER 720
#define REPORT_GENERATE 721
#define REPORT_READ_CDD_AND_READY 722
#define REPORT_CLOSE_CDD 723
#define REPORT_SAVE_CDD 724
#define REPORT_FORMAT_EXCLUSION_REASON 725
#define REPORT_OUTPUT_EXCLUSION_REASON 726
#define COMMAND_REPORT 727
#define SCOPE_FIND_FUNIT_FROM_SCOPE 728
#define SCOPE_FIND_PARAM 729
#define SCOPE_FIND_SIGNAL 730
#define SCOPE_FIND_TASK_FUNCTION_NAMEDBLOCK 731
#define SCOPE_GET_PARENT_FUNIT 732
#define SCOPE_GET_PARENT_MODULE 733
#define SCORE_GENERATE_TOP_VPI_MODULE 734
#define SCORE_GENERATE_TOP_DUMPVARS_MODULE 735
#define SCORE_GENERATE_PLI_TAB_FILE 736
#define SCORE_PARSE_DEFINE 737
#define SCORE_PARSE_ARGS 738
#define COMMAND_SCORE 739
#define SEARCH_INIT 740
#define SEARCH_ADD_INCLUDE_PATH 741
#define SEARCH_ADD_DIRECTORY_PATH 742
#define SEARCH_ADD_FILE 743
#define SEARCH_ADD_NO_SCORE_FUNIT 744
#define SEARCH_ADD_EXTENSIONS 745
#define SEARCH_FREE_LISTS 746
#define SIM_CURRENT_THREAD 747
#define SIM_THREAD_POP_HEAD 748
#define SIM_THREAD_INSERT_INTO_DELAY_QUEUE 749
#define SIM_THREAD_PUSH 750
#define SIM_EXPR_CHANGED 751
#define SIM_CREATE_THREAD 752
#define SIM_ADD_THREAD 753
#define SIM_KILL_THREAD 754
#define SIM_KILL_THREAD_WITH_FUNIT 755
#define SIM_ADD_STATICS 756
#define SIM_EXPRESSION 757
#define SIM_THREAD 758
#define SIM_SIMULATE 759
#define SIM_INITIALIZE 760
#define SIM_STOP 761
#define SIM_FINISH 762
#define SIM_DEALLOC 763
#define STATISTIC_CREATE 764
#define STATISTIC_IS_EMPTY 765
#define STATISTIC_DEALLOC 766
#define STATEMENT_CREATE 767
#define STATEMENT_QUEUE_ADD 768
#define STATEMENT_QUEUE_COMPARE 769
#define STATEMENT_SIZE_ELEMENTS 770
#define STATEMENT_DB_WRITE 771
#define STATEMENT_DB_WRITE_TREE 772
#define STATEMENT_DB_WRITE_EXPR_TREE 773
#define STATEMENT_DB_READ 774
#define STATEMENT_ASSIGN_EXPR_IDS 775
#define STATEMENT_CONNECT 776
#define STATEMENT_GET_LAST_LINE_HELPER 777
#define STATEMENT_GET_LAST_LINE 778
#define STATEMENT_FIND_RHS_SIGS 779
#define STATEMENT_FIND_HEAD_STATEMENT 780
#define STATEMENT_FIND_STATEMENT 781
#define STATEMENT_CONTAINS_EXPR_CALLING_STMT 782
#define STATEMENT_DEALLOC_RECURSIVE 783
#define STATEMENT_DEALLOC 784
#define STATIC_EXPR_GEN_UNARY 785
#define STATIC_EXPR_GEN 786
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_PRE 787
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_POST 788
#define STATIC_EXPR_DEALLOC 789
#define STMT_BLK_ADD_TO_REMOVE_LIST 790
#define STMT_BLK_REMOVE 791
#define STMT_BLK_SPECIFY_REMOVAL_REASON 792
#define STRUCT_UNION_LENGTH 793
#define STRUCT_UNION_ADD_MEMBER 794
#define STRUCT_UNION_ADD_MEMBER_VOID 795
#define STRUCT_UNION_ADD_MEMBER_SIG 796
#define STRUCT_UNION_ADD_MEMBER_TYPEDEF 797
#define STRUCT_UNION_ADD_MEMBER_ENUM 798
#define STRUCT_UNION_ADD_MEMBER_STRUCT_UNION 799
#define STRUCT_UNION_CREATE 800
#define STRUCT_UNION_MEMBER_DEALLOC 801
#define STRUCT_UNION_DEALLOC 802
#define STRUCT_UNION_DEALLOC_LIST 803
#define SYMTABLE_ADD_SYM_SIG 804
#define SYMTABLE_INIT 805
#define SYMTABLE_CREATE 806
#define SYMTABLE_ADD 807
#define SYMTABLE_SET_VALUE 808
#define SYMTABLE_ASSIGN 809
#define SYMTABLE_DEALLOC 810
#define SYS_TASK_UNIFORM 811
#define SYS_TASK_RTL_DIST_UNIFORM 812
#define SYS_TASK_SRANDOM 813
#define SYS_TASK_RANDOM 814
#define SYS_TASK_URANDOM 815
#define SYS_TASK_URANDOM_RANGE 816
#define SYS_TASK_REALTOBITS 817
#define SYS_TASK_BITSTOREAL 818
#define SYS_TASK_SHORTREALTOBITS 819
#define SYS_TASK_BITSTOSHORTREAL 820
#define SYS_TASK_ITOR 821
#define SYS_TASK_RTOI 822
#define SYS_TASK_STORE_PLUSARGS 823
#define SYS_TASK_TEST_PLUSARG 824
#define SYS_TASK_VALUE_PLUSARGS 825
#define SYS_TASK_DEALLOC 826
#define TCL_FUNC_GET_RACE_REASON_MSGS 827
#define TCL_FUNC_GET_FUNIT_LIST 828
#define TCL_FUNC_GET_INSTANCES 829
#define TCL_FUNC_GET_INSTANCE_LIST 830
#define TCL_FUNC_IS_FUNIT 831
#define TCL_FUNC_GET_FUNIT 832
#define TCL_FUNC_GET_INST 833
#define TCL_FUNC_GET_FUNIT_NAME 834
#define TCL_FUNC_GET_FILENAME 835
#define TCL_FUNC_INST_SCOPE 836
#define TCL_FUNC_GET_FUNIT_START_AND_END 837
#define TCL_FUNC_COLLECT_UNCOVERED_LINES 838
#define TCL_FUNC_COLLECT_COVERED_LINES 839
#define TCL_FUNC_COLLECT_RACE_LINES 840
#define TCL_FUNC_COLLECT_UNCOVERED_TOGGLES 841
#define TCL_FUNC_COLLECT_COVERED_TOGGLES 842
#define TCL_FUNC_COLLECT_UNCOVERED_MEMORIES 843
#define TCL_FUNC_COLLECT_COVERED_MEMORIES 844
#define TCL_FUNC_GET_TOGGLE_COVERAGE 845
#define TCL_FUNC_GET_MEMORY_COVERAGE 846
#define TCL_FUNC_COLLECT_UNCOVERED_COMBS 847
#define TCL_FUNC_COLLECT_COVERED_COMBS 848
#define TCL_FUNC_GET_COMB_EXPRESSION 849
#define TCL_FUNC_GET_COMB_COVERAGE 850
#define TCL_FUNC_COLLECT_UNCOVERED_FSMS 851
#define TCL_FUNC_COLLECT_COVERED_FSMS 852
#define TCL_FUNC_GET_FSM_COVERAGE 853
#define TCL_FUNC_COLLECT_UNCOVERED_ASSERTIONS 854
#define TCL_FUNC_COLLECT_COVERED_ASSERTIONS 855
#define TCL_FUNC_GET_ASSERT_COVERAGE 856
#define TCL_FUNC_OPEN_CDD 857
#define TCL_FUNC_CLOSE_CDD 858
#define TCL_FUNC_SAVE_CDD 859
#define TCL_FUNC_MERGE_CDD 860
#define TCL_FUNC_GET_LINE_SUMMARY 861
#define TCL_FUNC_GET_TOGGLE_SUMMARY 862
#define TCL_FUNC_GET_MEMORY_SUMMARY 863
#define TCL_FUNC_GET_COMB_SUMMARY 864
#define TCL_FUNC_GET_FSM_SUMMARY 865
#define TCL_FUNC_GET_ASSERT_SUMMARY 866
#define TCL_FUNC_PREPROCESS_VERILOG 867
#define TCL_FUNC_GET_SCORE_PATH 868
#define TCL_FUNC_GET_INCLUDE_PATHNAME 869
#define TCL_FUNC_GET_GENERATION 870
#define TCL_FUNC_SET_LINE_EXCLUDE 871
#define TCL_FUNC_SET_TOGGLE_EXCLUDE 872
#define TCL_FUNC_SET_MEMORY_EXCLUDE 873
#define TCL_FUNC_SET_COMB_EXCLUDE 874
#define TCL_FUNC_FSM_EXCLUDE 875
#define TCL_FUNC_SET_ASSERT_EXCLUDE 876
#define TCL_FUNC_GENERATE_REPORT 877
#define TCL_FUNC_INITIALIZE 878
#define TOGGLE_GET_STATS 879
#define TOGGLE_COLLECT 880
#define TOGGLE_GET_COVERAGE 881
#define TOGGLE_GET_FUNIT_SUMMARY 882
#define TOGGLE_GET_INST_SUMMARY 883
#define TOGGLE_DISPLAY_INSTANCE_SUMMARY 884
#define TOGGLE_INSTANCE_SUMMARY 885
#define TOGGLE_DISPLAY_FUNIT_SUMMARY 886
#define TOGGLE_FUNIT_SUMMARY 887
#define TOGGLE_DISPLAY_VERBOSE 888
#define TOGGLE_INSTANCE_VERBOSE 889
#define TOGGLE_FUNIT_VERBOSE 890
#define TOGGLE_REPORT 891
#define TREE_ADD 892
#define TREE_FIND 893
#define TREE_REMOVE 894
#define TREE_DEALLOC 895
#define CHECK_OPTION_VALUE 896
#define IS_VARIABLE 897
#define IS_FUNC_UNIT 898
#define IS_LEGAL_FILENAME 899
#define GET_BASENAME 900
#define GET_DIRNAME 901
#define GET_ABSOLUTE_PATH 902
#define GET_RELATIVE_PATH 903
#define DIRECTORY_EXISTS 904
#define DIRECTORY_LOAD 905
#define FILE_EXISTS 906
#define UTIL_READLINE 907
#define GET_QUOTED_STRING 908
#define SUBSTITUTE_ENV_VARS 909
#define SCOPE_EXTRACT_FRONT 910
#define SCOPE_EXTRACT_BACK 911
#define SCOPE_EXTRACT_SCOPE 912
#define SCOPE_GEN_PRINTABLE 913
#define SCOPE_COMPARE 914
#define SCOPE_LOCAL 915
#define CONVERT_FILE_TO_MODULE 916
#define GET_NEXT_VFILE 917
#define GEN_SPACE 918
#define REMOVE_UNDERSCORES 919
#define GET_FUNIT_TYPE 920
#define CALC_MISS_PERCENT 921
#define READ_COMMAND_FILE 922
#define VCD_PARSE_DEF_IGNORE 923
#define VCD_PARSE_DEF_VAR 924
#define VCD_PARSE_DEF_SCOPE 925
#define VCD_PARSE_DEF 926
#define VCD_PARSE_SIM_VECTOR 927
#define VCD_PARSE_SIM_REAL 928
#define VCD_PARSE_SIM_IGNORE 929
#define VCD_PARSE_SIM 930
#define VCD_PARSE 931
#define VECTOR_INIT 932
#define VECTOR_INT_R64 933
#define VECTOR_INT_R32 934
#define VECTOR_CREATE 935
#define VECTOR_COPY 936
#define VECTOR_COPY_RANGE 937
#define VECTOR_CLONE 938
#define VECTOR_DB_WRITE 939
#define VECTOR_DB_READ 940
#define VECTOR_DB_MERGE 941
#define VECTOR_MERGE 942
#define VECTOR_GET_EVAL_A 943
#define VECTOR_GET_EVAL_B 944
#define VECTOR_GET_EVAL_C 945
#define VECTOR_GET_EVAL_D 946
#define VECTOR_GET_EVAL_AB_COUNT 947
#define VECTOR_GET_EVAL_ABC_COUNT 948
#define VECTOR_GET_EVAL_ABCD_COUNT 949
#define VECTOR_GET_TOGGLE01_ULONG 950
#define VECTOR_GET_TOGGLE10_ULONG 951
#define VECTOR_DISPLAY_TOGGLE01_ULONG 952
#define VECTOR_DISPLAY_TOGGLE10_ULONG 953
#define VECTOR_TOGGLE_COUNT 954
#define VECTOR_MEM_RW_COUNT 955
#define VECTOR_SET_ASSIGNED 956
#define VECTOR_SET_COVERAGE_AND_ASSIGN 957
#define VECTOR_GET_SIGN_EXTEND_VECTOR_ULONG 958
#define VECTOR_SIGN_EXTEND_ULONG 959
#define VECTOR_LSHIFT_ULONG 960
#define VECTOR_RSHIFT_ULONG 961
#define VECTOR_SET_VALUE 962
#define VECTOR_PART_SELECT_PULL 963
#define VECTOR_PART_SELECT_PUSH 964
#define VECTOR_SET_UNARY_EVALS 965
#define VECTOR_SET_AND_COMB_EVALS 966
#define VECTOR_SET_OR_COMB_EVALS 967
#define VECTOR_SET_OTHER_COMB_EVALS 968
#define VECTOR_IS_UKNOWN 969
#define VECTOR_IS_NOT_ZERO 970
#define VECTOR_SET_TO_X 971
#define VECTOR_TO_INT 972
#define VECTOR_TO_UINT64 973
#define VECTOR_TO_REAL64 974
#define VECTOR_TO_SIM_TIME 975
#define VECTOR_FROM_INT 976
#define VECTOR_FROM_UINT64 977
#define VECTOR_FROM_REAL64 978
#define VECTOR_SET_STATIC 979
#define VECTOR_TO_STRING 980
#define VECTOR_FROM_STRING_FIXED 981
#define VECTOR_FROM_STRING 982
#define VECTOR_VCD_ASSIGN 983
#define VECTOR_BITWISE_AND_OP 984
#define VECTOR_BITWISE_NAND_OP 985
#define VECTOR_BITWISE_OR_OP 986
#define VECTOR_BITWISE_NOR_OP 987
#define VECTOR_BITWISE_XOR_OP 988
#define VECTOR_BITWISE_NXOR_OP 989
#define VECTOR_OP_LT 990
#define VECTOR_OP_LE 991
#define VECTOR_OP_GT 992
#define VECTOR_OP_GE 993
#define VECTOR_OP_EQ 994
#define VECTOR_CEQ_ULONG 995
#define VECTOR_OP_CEQ 996
#define VECTOR_OP_CXEQ 997
#define VECTOR_OP_CZEQ 998
#define VECTOR_OP_NE 999
#define VECTOR_OP_CNE 1000
#define VECTOR_OP_LOR 1001
#define VECTOR_OP_LAND 1002
#define VECTOR_OP_LSHIFT 1003
#define VECTOR_OP_RSHIFT 1004
#define VECTOR_OP_ARSHIFT 1005
#define VECTOR_OP_ADD 1006
#define VECTOR_OP_NEGATE 1007
#define VECTOR_OP_SUBTRACT 1008
#define VECTOR_OP_MULTIPLY 1009
#define VECTOR_OP_DIVIDE 1010
#define VECTOR_OP_MODULUS 1011
#define VECTOR_OP_INC 1012
#define VECTOR_OP_DEC 1013
#define VECTOR_UNARY_INV 1014
#define VECTOR_UNARY_AND 1015
#define VECTOR_UNARY_NAND 1016
#define VECTOR_UNARY_OR 1017
#define VECTOR_UNARY_NOR 1018
#define VECTOR_UNARY_XOR 1019
#define VECTOR_UNARY_NXOR 1020
#define VECTOR_UNARY_NOT 1021
#define VECTOR_OP_EXPAND 1022
#define VECTOR_OP_LIST 1023
#define VECTOR_DEALLOC_VALUE 1024
#define VECTOR_DEALLOC 1025
#define SYM_VALUE_STORE 1026
#define ADD_SYM_VALUES_TO_SIM 1027
#define COVERED_VALUE_CHANGE_BIN 1028
#define COVERED_VALUE_CHANGE_REAL 1029
#define COVERED_END_OF_SIM 1030
#define COVERED_CB_ERROR_HANDLER 1031
#define GEN_NEXT_SYMBOL 1032
#define COVERED_CREATE_VALUE_CHANGE_CB 1033
#define COVERED_PARSE_TASK_FUNC 1034
#define COVERED_PARSE_SIGNALS 1035
#define COVERED_PARSE_INSTANCE 1036
#define COVERED_SIM_CALLTF 1037
#define VSIGNAL_INIT 1038
#define VSIGNAL_CREATE 1039
#define VSIGNAL_CREATE_VEC 1040
#define VSIGNAL_DUPLICATE 1041
#define VSIGNAL_DB_WRITE 1042
#define VSIGNAL_DB_READ 1043
#define VSIGNAL_DB_MERGE 1044
#define VSIGNAL_MERGE 1045
#define VSIGNAL_PROPAGATE 1046
#define VSIGNAL_VCD_ASSIGN 1047
#define VSIGNAL_ADD_EXPRESSION 1048
#define VSIGNAL_FROM_STRING 1049
#define VSIGNAL_CALC_WIDTH_FOR_EXPR 1050
#define VSIGNAL_CALC_LSB_FOR_EXPR 1051
#define VSIGNAL_DEALLOC 1052

extern profiler profiles[NUM_PROFILES];
#endif

extern unsigned int profile_index;

#endif

