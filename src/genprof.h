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

#define NUM_PROFILES 960

#ifdef DEBUG
#define UNREGISTERED 0
#define FSM_ARG_PARSE_STATE 1
#define FSM_ARG_PARSE 2
#define FSM_ARG_PARSE_VALUE 3
#define FSM_ARG_PARSE_TRANS 4
#define FSM_ARG_PARSE_ATTR 5
#define SYM_VALUE_STORE 6
#define ADD_SYM_VALUES_TO_SIM 7
#define COVERED_VALUE_CHANGE 8
#define COVERED_END_OF_SIM 9
#define COVERED_CB_ERROR_HANDLER 10
#define GEN_NEXT_SYMBOL 11
#define COVERED_CREATE_VALUE_CHANGE_CB 12
#define COVERED_PARSE_TASK_FUNC 13
#define COVERED_PARSE_SIGNALS 14
#define COVERED_PARSE_INSTANCE 15
#define COVERED_SIM_CALLTF 16
#define COVERED_REGISTER 17
#define LEXER_KEYWORD_SV_CODE 18
#define VSIGNAL_INIT 19
#define VSIGNAL_CREATE 20
#define VSIGNAL_CREATE_VEC 21
#define VSIGNAL_DUPLICATE 22
#define VSIGNAL_DB_WRITE 23
#define VSIGNAL_DB_READ 24
#define VSIGNAL_DB_MERGE 25
#define VSIGNAL_MERGE 26
#define VSIGNAL_PROPAGATE 27
#define VSIGNAL_VCD_ASSIGN 28
#define VSIGNAL_ADD_EXPRESSION 29
#define VSIGNAL_FROM_STRING 30
#define VSIGNAL_CALC_WIDTH_FOR_EXPR 31
#define VSIGNAL_CALC_LSB_FOR_EXPR 32
#define VSIGNAL_DEALLOC 33
#define LEXER_KEYWORD_1995_CODE 34
#define STMT_ITER_RESET 35
#define STMT_ITER_COPY 36
#define STMT_ITER_NEXT 37
#define STMT_ITER_REVERSE 38
#define STMT_ITER_FIND_HEAD 39
#define STMT_ITER_GET_NEXT_IN_ORDER 40
#define STMT_ITER_GET_LINE_BEFORE 41
#define LEXER_CSTRING_A 42
#define LEXER_KEYWORD_A 43
#define LEXER_ESCAPED_NAME 44
#define LEXER_SYSTEM_CALL 45
#define LINE_DIRECTIVE 46
#define LINE_DIRECTIVE2 47
#define PROCESS_TIMESCALE_TOKEN 48
#define PROCESS_TIMESCALE 49
#define LEXER_YYWRAP 50
#define RESET_LEXER 51
#define CHECK_FOR_PRAGMA 52
#define STATEMENT_CREATE 53
#define STATEMENT_QUEUE_ADD 54
#define STATEMENT_QUEUE_COMPARE 55
#define STATEMENT_SIZE_ELEMENTS 56
#define STATEMENT_DB_WRITE 57
#define STATEMENT_DB_WRITE_TREE 58
#define STATEMENT_DB_WRITE_EXPR_TREE 59
#define STATEMENT_DB_READ 60
#define STATEMENT_ASSIGN_EXPR_IDS 61
#define STATEMENT_CONNECT 62
#define STATEMENT_GET_LAST_LINE_HELPER 63
#define STATEMENT_GET_LAST_LINE 64
#define STATEMENT_FIND_RHS_SIGS 65
#define STATEMENT_FIND_HEAD_STATEMENT 66
#define STATEMENT_FIND_STATEMENT 67
#define STATEMENT_CONTAINS_EXPR_CALLING_STMT 68
#define STATEMENT_DEALLOC_RECURSIVE 69
#define STATEMENT_DEALLOC 70
#define ENUMERATE_ADD_ITEM 71
#define ENUMERATE_END_LIST 72
#define ENUMERATE_RESOLVE 73
#define ENUMERATE_DEALLOC 74
#define ENUMERATE_DEALLOC_LIST 75
#define PARSER_PORT_DECLARATION_A 76
#define PARSER_PORT_DECLARATION_B 77
#define PARSER_PORT_DECLARATION_C 78
#define PARSER_STATIC_EXPR_PRIMARY_A 79
#define PARSER_STATIC_EXPR_PRIMARY_B 80
#define PARSER_EXPRESSION_LIST_A 81
#define PARSER_EXPRESSION_LIST_B 82
#define PARSER_EXPRESSION_LIST_C 83
#define PARSER_EXPRESSION_LIST_D 84
#define PARSER_IDENTIFIER_A 85
#define PARSER_GENERATE_CASE_ITEM_A 86
#define PARSER_GENERATE_CASE_ITEM_B 87
#define PARSER_GENERATE_CASE_ITEM_C 88
#define PARSER_STATEMENT_BEGIN_A 89
#define PARSER_STATEMENT_FORK_A 90
#define PARSER_STATEMENT_FOR_A 91
#define PARSER_CASE_ITEM_A 92
#define PARSER_CASE_ITEM_B 93
#define PARSER_CASE_ITEM_C 94
#define PARSER_DELAY_VALUE_A 95
#define PARSER_DELAY_VALUE_B 96
#define PARSER_PARAMETER_VALUE_BYNAME_A 97
#define PARSER_GATE_INSTANCE_A 98
#define PARSER_GATE_INSTANCE_B 99
#define PARSER_GATE_INSTANCE_C 100
#define PARSER_GATE_INSTANCE_D 101
#define PARSER_LIST_OF_NAMES_A 102
#define PARSER_LIST_OF_NAMES_B 103
#define ATTRIBUTE_CREATE 104
#define ATTRIBUTE_PARSE 105
#define ATTRIBUTE_DEALLOC 106
#define SEARCH_INIT 107
#define SEARCH_ADD_INCLUDE_PATH 108
#define SEARCH_ADD_DIRECTORY_PATH 109
#define SEARCH_ADD_FILE 110
#define SEARCH_ADD_NO_SCORE_FUNIT 111
#define SEARCH_ADD_EXTENSIONS 112
#define SEARCH_FREE_LISTS 113
#define RANK_CREATE_COMP_CDD_COV 114
#define RANK_DEALLOC_COMP_CDD_COV 115
#define RANK_CHECK_INDEX 116
#define RANK_GATHER_SIGNAL_COV 117
#define RANK_GATHER_COMB_COV 118
#define RANK_GATHER_EXPRESSION_COV 119
#define RANK_GATHER_FSM_COV 120
#define RANK_CALC_NUM_CPS 121
#define RANK_GATHER_COMP_CDD_COV 122
#define RANK_READ_CDD 123
#define RANK_SELECTED_CDD_COV 124
#define RANK_PERFORM_WEIGHTED_SELECTION 125
#define RANK_PERFORM_GREEDY_SORT 126
#define RANK_PERFORM 127
#define RANK_OUTPUT 128
#define COMMAND_RANK 129
#define SIM_CURRENT_THREAD 130
#define SIM_THREAD_POP_HEAD 131
#define SIM_THREAD_INSERT_INTO_DELAY_QUEUE 132
#define SIM_THREAD_PUSH 133
#define SIM_EXPR_CHANGED 134
#define SIM_CREATE_THREAD 135
#define SIM_ADD_THREAD 136
#define SIM_KILL_THREAD 137
#define SIM_KILL_THREAD_WITH_FUNIT 138
#define SIM_ADD_STATICS 139
#define SIM_EXPRESSION 140
#define SIM_THREAD 141
#define SIM_SIMULATE 142
#define SIM_INITIALIZE 143
#define SIM_STOP 144
#define SIM_FINISH 145
#define SIM_DEALLOC 146
#define SCOPE_FIND_FUNIT_FROM_SCOPE 147
#define SCOPE_FIND_PARAM 148
#define SCOPE_FIND_SIGNAL 149
#define SCOPE_FIND_TASK_FUNCTION_NAMEDBLOCK 150
#define SCOPE_GET_PARENT_FUNIT 151
#define SCOPE_GET_PARENT_MODULE 152
#define REPORT_PARSE_METRICS 153
#define REPORT_PARSE_ARGS 154
#define REPORT_GATHER_INSTANCE_STATS 155
#define REPORT_GATHER_FUNIT_STATS 156
#define REPORT_PRINT_HEADER 157
#define REPORT_GENERATE 158
#define REPORT_READ_CDD_AND_READY 159
#define REPORT_CLOSE_CDD 160
#define REPORT_SAVE_CDD 161
#define COMMAND_REPORT 162
#define CHECK_OPTION_VALUE 163
#define IS_VARIABLE 164
#define IS_FUNC_UNIT 165
#define IS_LEGAL_FILENAME 166
#define GET_BASENAME 167
#define GET_DIRNAME 168
#define DIRECTORY_EXISTS 169
#define DIRECTORY_LOAD 170
#define FILE_EXISTS 171
#define UTIL_READLINE 172
#define GET_QUOTED_STRING 173
#define SUBSTITUTE_ENV_VARS 174
#define SCOPE_EXTRACT_FRONT 175
#define SCOPE_EXTRACT_BACK 176
#define SCOPE_EXTRACT_SCOPE 177
#define SCOPE_GEN_PRINTABLE 178
#define SCOPE_COMPARE 179
#define SCOPE_LOCAL 180
#define CONVERT_FILE_TO_MODULE 181
#define GET_NEXT_VFILE 182
#define GEN_SPACE 183
#define GET_FUNIT_TYPE 184
#define CALC_MISS_PERCENT 185
#define READ_COMMAND_FILE 186
#define OVL_IS_ASSERTION_NAME 187
#define OVL_IS_ASSERTION_MODULE 188
#define OVL_IS_COVERAGE_POINT 189
#define OVL_ADD_ASSERTIONS_TO_NO_SCORE_LIST 190
#define OVL_GET_FUNIT_STATS 191
#define OVL_GET_COVERAGE_POINT 192
#define OVL_DISPLAY_VERBOSE 193
#define OVL_COLLECT 194
#define OVL_GET_COVERAGE 195
#define COMBINATION_CALC_DEPTH 196
#define COMBINATION_DOES_MULTI_EXP_NEED_UL 197
#define COMBINATION_MULTI_EXPR_CALC 198
#define COMBINATION_IS_EXPR_MULTI_NODE 199
#define COMBINATION_GET_TREE_STATS 200
#define COMBINATION_RESET_COUNTED_EXPRS 201
#define COMBINATION_RESET_COUNTED_EXPR_TREE 202
#define COMBINATION_GET_STATS 203
#define COMBINATION_GET_FUNIT_SUMMARY 204
#define COMBINATION_GET_INST_SUMMARY 205
#define COMBINATION_DISPLAY_INSTANCE_SUMMARY 206
#define COMBINATION_INSTANCE_SUMMARY 207
#define COMBINATION_DISPLAY_FUNIT_SUMMARY 208
#define COMBINATION_FUNIT_SUMMARY 209
#define COMBINATION_DRAW_LINE 210
#define COMBINATION_DRAW_CENTERED_LINE 211
#define COMBINATION_UNDERLINE_TREE 212
#define COMBINATION_PREP_LINE 213
#define COMBINATION_UNDERLINE 214
#define COMBINATION_UNARY 215
#define COMBINATION_EVENT 216
#define COMBINATION_TWO_VARS 217
#define COMBINATION_MULTI_VAR_EXPRS 218
#define COMBINATION_MULTI_EXPR_OUTPUT_LENGTH 219
#define COMBINATION_MULTI_EXPR_OUTPUT 220
#define COMBINATION_MULTI_VARS 221
#define COMBINATION_GET_MISSED_EXPR 222
#define COMBINATION_LIST_MISSED 223
#define COMBINATION_OUTPUT_EXPR 224
#define COMBINATION_DISPLAY_VERBOSE 225
#define COMBINATION_INSTANCE_VERBOSE 226
#define COMBINATION_FUNIT_VERBOSE 227
#define COMBINATION_COLLECT 228
#define COMBINATION_GET_EXCLUDE_LIST 229
#define COMBINATION_GET_EXPRESSION 230
#define COMBINATION_GET_COVERAGE 231
#define COMBINATION_REPORT 232
#define FUNIT_GET_START_AND_END_LINES 233
#define VCD_PARSE_DEF_IGNORE 234
#define VCD_PARSE_DEF_VAR 235
#define VCD_PARSE_DEF_SCOPE 236
#define VCD_PARSE_DEF 237
#define VCD_PARSE_SIM_VECTOR 238
#define VCD_PARSE_SIM_IGNORE 239
#define VCD_PARSE_SIM 240
#define VCD_PARSE 241
#define STR_LINK_ADD 242
#define STMT_LINK_ADD_HEAD 243
#define STMT_LINK_ADD_TAIL 244
#define STMT_LINK_MERGE 245
#define EXP_LINK_ADD 246
#define SIG_LINK_ADD 247
#define FSM_LINK_ADD 248
#define FUNIT_LINK_ADD 249
#define GITEM_LINK_ADD 250
#define INST_LINK_ADD 251
#define STR_LINK_FIND 252
#define STMT_LINK_FIND 253
#define EXP_LINK_FIND 254
#define SIG_LINK_FIND 255
#define FSM_LINK_FIND 256
#define FUNIT_LINK_FIND 257
#define GITEM_LINK_FIND 258
#define INST_LINK_FIND_BY_SCOPE 259
#define INST_LINK_FIND_BY_FUNIT 260
#define STR_LINK_REMOVE 261
#define EXP_LINK_REMOVE 262
#define GITEM_LINK_REMOVE 263
#define FUNIT_LINK_REMOVE 264
#define INST_LINK_FLATTEN 265
#define STR_LINK_DELETE_LIST 266
#define STMT_LINK_UNLINK 267
#define STMT_LINK_DELETE_LIST 268
#define EXP_LINK_DELETE_LIST 269
#define SIG_LINK_DELETE_LIST 270
#define FSM_LINK_DELETE_LIST 271
#define FUNIT_LINK_DELETE_LIST 272
#define GITEM_LINK_DELETE_LIST 273
#define INST_LINK_DELETE_LIST 274
#define SCORE_GENERATE_TOP_VPI_MODULE 275
#define SCORE_GENERATE_PLI_TAB_FILE 276
#define SCORE_PARSE_DEFINE 277
#define SCORE_ADD_ARG 278
#define SCORE_PARSE_ARGS 279
#define COMMAND_SCORE 280
#define MEMORY_GET_STAT 281
#define MEMORY_GET_STATS 282
#define MEMORY_GET_FUNIT_SUMMARY 283
#define MEMORY_GET_INST_SUMMARY 284
#define MEMORY_CREATE_PDIM_BIT_ARRAY 285
#define MEMORY_GET_MEM_COVERAGE 286
#define MEMORY_GET_COVERAGE 287
#define MEMORY_COLLECT 288
#define MEMORY_DISPLAY_TOGGLE_INSTANCE_SUMMARY 289
#define MEMORY_TOGGLE_INSTANCE_SUMMARY 290
#define MEMORY_DISPLAY_AE_INSTANCE_SUMMARY 291
#define MEMORY_AE_INSTANCE_SUMMARY 292
#define MEMORY_DISPLAY_TOGGLE_FUNIT_SUMMARY 293
#define MEMORY_TOGGLE_FUNIT_SUMMARY 294
#define MEMORY_DISPLAY_AE_FUNIT_SUMMARY 295
#define MEMORY_AE_FUNIT_SUMMARY 296
#define MEMORY_DISPLAY_MEMORY 297
#define MEMORY_DISPLAY_VERBOSE 298
#define MEMORY_INSTANCE_VERBOSE 299
#define MEMORY_FUNIT_VERBOSE 300
#define MEMORY_REPORT 301
#define DB_CREATE 302
#define DB_CLOSE 303
#define DB_CHECK_FOR_TOP_MODULE 304
#define DB_WRITE 305
#define DB_READ 306
#define DB_MERGE_FUNITS 307
#define DB_SCALE_TO_PRECISION 308
#define DB_CREATE_UNNAMED_SCOPE 309
#define DB_IS_UNNAMED_SCOPE 310
#define DB_SET_TIMESCALE 311
#define DB_GET_CURR_FUNIT 312
#define DB_ADD_INSTANCE 313
#define DB_ADD_MODULE 314
#define DB_END_MODULE 315
#define DB_ADD_FUNCTION_TASK_NAMEDBLOCK 316
#define DB_END_FUNCTION_TASK_NAMEDBLOCK 317
#define DB_ADD_DECLARED_PARAM 318
#define DB_ADD_OVERRIDE_PARAM 319
#define DB_ADD_VECTOR_PARAM 320
#define DB_ADD_DEFPARAM 321
#define DB_ADD_SIGNAL 322
#define DB_ADD_ENUM 323
#define DB_END_ENUM_LIST 324
#define DB_ADD_TYPEDEF 325
#define DB_FIND_SIGNAL 326
#define DB_ADD_GEN_ITEM_BLOCK 327
#define DB_FIND_GEN_ITEM 328
#define DB_FIND_TYPEDEF 329
#define DB_GET_CURR_GEN_BLOCK 330
#define DB_CURR_SIGNAL_COUNT 331
#define DB_CREATE_EXPRESSION 332
#define DB_BIND_EXPR_TREE 333
#define DB_CREATE_EXPR_FROM_STATIC 334
#define DB_ADD_EXPRESSION 335
#define DB_CREATE_SENSITIVITY_LIST 336
#define DB_PARALLELIZE_STATEMENT 337
#define DB_CREATE_STATEMENT 338
#define DB_ADD_STATEMENT 339
#define DB_REMOVE_STATEMENT_FROM_CURRENT_FUNIT 340
#define DB_REMOVE_STATEMENT 341
#define DB_CONNECT_STATEMENT_TRUE 342
#define DB_CONNECT_STATEMENT_FALSE 343
#define DB_GEN_ITEM_CONNECT_TRUE 344
#define DB_GEN_ITEM_CONNECT_FALSE 345
#define DB_GEN_ITEM_CONNECT 346
#define DB_STATEMENT_CONNECT 347
#define DB_CREATE_ATTR_PARAM 348
#define DB_PARSE_ATTRIBUTE 349
#define DB_REMOVE_STMT_BLKS_CALLING_STATEMENT 350
#define DB_GEN_CURR_INST_SCOPE 351
#define DB_SYNC_CURR_INSTANCE 352
#define DB_SET_VCD_SCOPE 353
#define DB_VCD_UPSCOPE 354
#define DB_ASSIGN_SYMBOL 355
#define DB_SET_SYMBOL_CHAR 356
#define DB_SET_SYMBOL_STRING 357
#define DB_DO_TIMESTEP 358
#define FSM_CREATE 359
#define FSM_ADD_ARC 360
#define FSM_CREATE_TABLES 361
#define FSM_DB_WRITE 362
#define FSM_DB_READ 363
#define FSM_DB_MERGE 364
#define FSM_MERGE 365
#define FSM_TABLE_SET 366
#define FSM_GET_STATS 367
#define FSM_GET_FUNIT_SUMMARY 368
#define FSM_GET_INST_SUMMARY 369
#define FSM_GATHER_SIGNALS 370
#define FSM_COLLECT 371
#define FSM_GET_COVERAGE 372
#define FSM_DISPLAY_INSTANCE_SUMMARY 373
#define FSM_INSTANCE_SUMMARY 374
#define FSM_DISPLAY_FUNIT_SUMMARY 375
#define FSM_FUNIT_SUMMARY 376
#define FSM_DISPLAY_STATE_VERBOSE 377
#define FSM_DISPLAY_ARC_VERBOSE 378
#define FSM_DISPLAY_VERBOSE 379
#define FSM_INSTANCE_VERBOSE 380
#define FSM_FUNIT_VERBOSE 381
#define FSM_REPORT 382
#define FSM_DEALLOC 383
#define CODEGEN_CREATE_EXPR_HELPER 384
#define CODEGEN_CREATE_EXPR 385
#define CODEGEN_GEN_EXPR 386
#define TOGGLE_GET_STATS 387
#define TOGGLE_COLLECT 388
#define TOGGLE_GET_COVERAGE 389
#define TOGGLE_GET_FUNIT_SUMMARY 390
#define TOGGLE_GET_INST_SUMMARY 391
#define TOGGLE_DISPLAY_INSTANCE_SUMMARY 392
#define TOGGLE_INSTANCE_SUMMARY 393
#define TOGGLE_DISPLAY_FUNIT_SUMMARY 394
#define TOGGLE_FUNIT_SUMMARY 395
#define TOGGLE_DISPLAY_VERBOSE 396
#define TOGGLE_INSTANCE_VERBOSE 397
#define TOGGLE_FUNIT_VERBOSE 398
#define TOGGLE_REPORT 399
#define VLERROR 400
#define VLWARN 401
#define PARSER_DEALLOC_SIG_RANGE 402
#define PARSER_COPY_CURR_RANGE 403
#define PARSER_COPY_RANGE_TO_CURR_RANGE 404
#define PARSER_EXPLICITLY_SET_CURR_RANGE 405
#define PARSER_IMPLICITLY_SET_CURR_RANGE 406
#define PARSER_CHECK_GENERATION 407
#define LEXER_KEYWORD_2001_CODE 408
#define STRUCT_UNION_LENGTH 409
#define STRUCT_UNION_ADD_MEMBER 410
#define STRUCT_UNION_ADD_MEMBER_VOID 411
#define STRUCT_UNION_ADD_MEMBER_SIG 412
#define STRUCT_UNION_ADD_MEMBER_TYPEDEF 413
#define STRUCT_UNION_ADD_MEMBER_ENUM 414
#define STRUCT_UNION_ADD_MEMBER_STRUCT_UNION 415
#define STRUCT_UNION_CREATE 416
#define STRUCT_UNION_MEMBER_DEALLOC 417
#define STRUCT_UNION_DEALLOC 418
#define STRUCT_UNION_DEALLOC_LIST 419
#define BIND_ADD 420
#define BIND_APPEND_FSM_EXPR 421
#define BIND_REMOVE 422
#define BIND_FIND_SIG_NAME 423
#define BIND_PARAM 424
#define BIND_SIGNAL 425
#define BIND_TASK_FUNCTION_PORTS 426
#define BIND_TASK_FUNCTION_NAMEDBLOCK 427
#define BIND_PERFORM 428
#define BIND_DEALLOC 429
#define PERF_GEN_STATS 430
#define PERF_OUTPUT_MOD_STATS 431
#define PERF_OUTPUT_INST_REPORT_HELPER 432
#define PERF_OUTPUT_INST_REPORT 433
#define MOD_PARM_FIND 434
#define MOD_PARM_FIND_EXPR_AND_REMOVE 435
#define MOD_PARM_ADD 436
#define INST_PARM_FIND 437
#define INST_PARM_ADD 438
#define INST_PARM_ADD_GENVAR 439
#define INST_PARM_BIND 440
#define DEFPARAM_ADD 441
#define DEFPARAM_DEALLOC 442
#define PARAM_FIND_AND_SET_EXPR_VALUE 443
#define PARAM_SET_SIG_SIZE 444
#define PARAM_SIZE_FUNCTION 445
#define PARAM_EXPR_EVAL 446
#define PARAM_HAS_OVERRIDE 447
#define PARAM_HAS_DEFPARAM 448
#define PARAM_RESOLVE_DECLARED 449
#define PARAM_RESOLVE_OVERRIDE 450
#define PARAM_RESOLVE 451
#define PARAM_DB_WRITE 452
#define MOD_PARM_DEALLOC 453
#define INST_PARM_DEALLOC 454
#define DEF_LOOKUP 455
#define IS_DEFINED 456
#define DEF_MATCH 457
#define DEF_START 458
#define DEFINE_MACRO 459
#define DO_DEFINE 460
#define DEF_IS_DONE 461
#define DEF_FINISH 462
#define DEF_UNDEFINE 463
#define INCLUDE_FILENAME 464
#define DO_INCLUDE 465
#define YYWRAP 466
#define RESET_PPLEXER 467
#define REENTRANT_COUNT_AFU_BITS 468
#define REENTRANT_STORE_DATA_BITS 469
#define REENTRANT_RESTORE_DATA_BITS 470
#define REENTRANT_CREATE 471
#define REENTRANT_DEALLOC 472
#define PARSE_READLINE 473
#define PARSE_DESIGN 474
#define PARSE_AND_SCORE_DUMPFILE 475
#define OBFUSCATE_SET_MODE 476
#define OBFUSCATE_NAME 477
#define OBFUSCATE_DEALLOC 478
#define INFO_INITIALIZE 479
#define INFO_SET_VECTOR_ELEM_SIZE 480
#define INFO_DB_WRITE 481
#define INFO_DB_READ 482
#define ARGS_DB_READ 483
#define MESSAGE_DB_READ 484
#define MERGED_CDD_DB_READ 485
#define INFO_DEALLOC 486
#define ASSERTION_PARSE 487
#define ASSERTION_PARSE_ATTR 488
#define ASSERTION_GET_STATS 489
#define ASSERTION_DISPLAY_INSTANCE_SUMMARY 490
#define ASSERTION_INSTANCE_SUMMARY 491
#define ASSERTION_DISPLAY_FUNIT_SUMMARY 492
#define ASSERTION_FUNIT_SUMMARY 493
#define ASSERTION_DISPLAY_VERBOSE 494
#define ASSERTION_INSTANCE_VERBOSE 495
#define ASSERTION_FUNIT_VERBOSE 496
#define ASSERTION_REPORT 497
#define ASSERTION_GET_FUNIT_SUMMARY 498
#define ASSERTION_COLLECT 499
#define ASSERTION_GET_COVERAGE 500
#define LXT2_RD_EXPAND_INTEGER_TO_BITS 501
#define LXT2_RD_EXPAND_BITS_TO_INTEGER 502
#define LXT2_RD_ITER_RADIX 503
#define LXT2_RD_ITER_RADIX0 504
#define LXT2_RD_BUILD_RADIX 505
#define LXT2_RD_REGENERATE_PROCESS_MASK 506
#define LXT2_RD_PROCESS_BLOCK 507
#define LXT2_RD_INIT 508
#define LXT2_RD_CLOSE 509
#define LXT2_RD_GET_FACNAME 510
#define LXT2_RD_ITER_BLOCKS 511
#define LXT2_RD_LIMIT_TIME_RANGE 512
#define LXT2_RD_UNLIMIT_TIME_RANGE 513
#define TREE_ADD 514
#define TREE_FIND 515
#define TREE_REMOVE 516
#define TREE_DEALLOC 517
#define EXPRESSION_CREATE_TMP_VECS 518
#define EXPRESSION_CREATE_VALUE 519
#define EXPRESSION_CREATE 520
#define EXPRESSION_SET_VALUE 521
#define EXPRESSION_SET_SIGNED 522
#define EXPRESSION_RESIZE 523
#define EXPRESSION_GET_ID 524
#define EXPRESSION_GET_FIRST_LINE_EXPR 525
#define EXPRESSION_GET_LAST_LINE_EXPR 526
#define EXPRESSION_GET_CURR_DIMENSION 527
#define EXPRESSION_FIND_RHS_SIGS 528
#define EXPRESSION_FIND_PARAMS 529
#define EXPRESSION_FIND_ULINE_ID 530
#define EXPRESSION_FIND_EXPR 531
#define EXPRESSION_CONTAINS_EXPR_CALLING_STMT 532
#define EXPRESSION_GET_ROOT_STATEMENT 533
#define EXPRESSION_ASSIGN_EXPR_IDS 534
#define EXPRESSION_DB_WRITE 535
#define EXPRESSION_DB_WRITE_TREE 536
#define EXPRESSION_DB_READ 537
#define EXPRESSION_DB_MERGE 538
#define EXPRESSION_MERGE 539
#define EXPRESSION_STRING_OP 540
#define EXPRESSION_STRING 541
#define EXPRESSION_OP_FUNC__XOR 542
#define EXPRESSION_OP_FUNC__XOR_A 543
#define EXPRESSION_OP_FUNC__MULTIPLY 544
#define EXPRESSION_OP_FUNC__MULTIPLY_A 545
#define EXPRESSION_OP_FUNC__DIVIDE 546
#define EXPRESSION_OP_FUNC__DIVIDE_A 547
#define EXPRESSION_OP_FUNC__MOD 548
#define EXPRESSION_OP_FUNC__MOD_A 549
#define EXPRESSION_OP_FUNC__ADD 550
#define EXPRESSION_OP_FUNC__ADD_A 551
#define EXPRESSION_OP_FUNC__SUBTRACT 552
#define EXPRESSION_OP_FUNC__SUB_A 553
#define EXPRESSION_OP_FUNC__AND 554
#define EXPRESSION_OP_FUNC__AND_A 555
#define EXPRESSION_OP_FUNC__OR 556
#define EXPRESSION_OP_FUNC__OR_A 557
#define EXPRESSION_OP_FUNC__NAND 558
#define EXPRESSION_OP_FUNC__NOR 559
#define EXPRESSION_OP_FUNC__NXOR 560
#define EXPRESSION_OP_FUNC__LT 561
#define EXPRESSION_OP_FUNC__GT 562
#define EXPRESSION_OP_FUNC__LSHIFT 563
#define EXPRESSION_OP_FUNC__LSHIFT_A 564
#define EXPRESSION_OP_FUNC__RSHIFT 565
#define EXPRESSION_OP_FUNC__RSHIFT_A 566
#define EXPRESSION_OP_FUNC__ARSHIFT 567
#define EXPRESSION_OP_FUNC__ARSHIFT_A 568
#define EXPRESSION_OP_FUNC__EQ 569
#define EXPRESSION_OP_FUNC__CEQ 570
#define EXPRESSION_OP_FUNC__LE 571
#define EXPRESSION_OP_FUNC__GE 572
#define EXPRESSION_OP_FUNC__NE 573
#define EXPRESSION_OP_FUNC__CNE 574
#define EXPRESSION_OP_FUNC__LOR 575
#define EXPRESSION_OP_FUNC__LAND 576
#define EXPRESSION_OP_FUNC__COND 577
#define EXPRESSION_OP_FUNC__COND_SEL 578
#define EXPRESSION_OP_FUNC__UINV 579
#define EXPRESSION_OP_FUNC__UAND 580
#define EXPRESSION_OP_FUNC__UNOT 581
#define EXPRESSION_OP_FUNC__UOR 582
#define EXPRESSION_OP_FUNC__UXOR 583
#define EXPRESSION_OP_FUNC__UNAND 584
#define EXPRESSION_OP_FUNC__UNOR 585
#define EXPRESSION_OP_FUNC__UNXOR 586
#define EXPRESSION_OP_FUNC__NULL 587
#define EXPRESSION_OP_FUNC__SIG 588
#define EXPRESSION_OP_FUNC__SBIT 589
#define EXPRESSION_OP_FUNC__MBIT 590
#define EXPRESSION_OP_FUNC__EXPAND 591
#define EXPRESSION_OP_FUNC__LIST 592
#define EXPRESSION_OP_FUNC__CONCAT 593
#define EXPRESSION_OP_FUNC__PEDGE 594
#define EXPRESSION_OP_FUNC__NEDGE 595
#define EXPRESSION_OP_FUNC__AEDGE 596
#define EXPRESSION_OP_FUNC__EOR 597
#define EXPRESSION_OP_FUNC__SLIST 598
#define EXPRESSION_OP_FUNC__DELAY 599
#define EXPRESSION_OP_FUNC__TRIGGER 600
#define EXPRESSION_OP_FUNC__CASE 601
#define EXPRESSION_OP_FUNC__CASEX 602
#define EXPRESSION_OP_FUNC__CASEZ 603
#define EXPRESSION_OP_FUNC__DEFAULT 604
#define EXPRESSION_OP_FUNC__BASSIGN 605
#define EXPRESSION_OP_FUNC__FUNC_CALL 606
#define EXPRESSION_OP_FUNC__TASK_CALL 607
#define EXPRESSION_OP_FUNC__NB_CALL 608
#define EXPRESSION_OP_FUNC__FORK 609
#define EXPRESSION_OP_FUNC__JOIN 610
#define EXPRESSION_OP_FUNC__DISABLE 611
#define EXPRESSION_OP_FUNC__REPEAT 612
#define EXPRESSION_OP_FUNC__EXPONENT 613
#define EXPRESSION_OP_FUNC__PASSIGN 614
#define EXPRESSION_OP_FUNC__MBIT_POS 615
#define EXPRESSION_OP_FUNC__MBIT_NEG 616
#define EXPRESSION_OP_FUNC__NEGATE 617
#define EXPRESSION_OP_FUNC__IINC 618
#define EXPRESSION_OP_FUNC__PINC 619
#define EXPRESSION_OP_FUNC__IDEC 620
#define EXPRESSION_OP_FUNC__PDEC 621
#define EXPRESSION_OP_FUNC__DLY_ASSIGN 622
#define EXPRESSION_OP_FUNC__DLY_OP 623
#define EXPRESSION_OP_FUNC__REPEAT_DLY 624
#define EXPRESSION_OP_FUNC__DIM 625
#define EXPRESSION_OP_FUNC__WAIT 626
#define EXPRESSION_OP_FUNC__FINISH 627
#define EXPRESSION_OP_FUNC__STOP 628
#define EXPRESSION_OPERATE 629
#define EXPRESSION_OPERATE_RECURSIVELY 630
#define EXPRESSION_IS_STATIC_ONLY 631
#define EXPRESSION_IS_ASSIGNED 632
#define EXPRESSION_IS_BIT_SELECT 633
#define EXPRESSION_IS_LAST_SELECT 634
#define EXPRESSION_IS_IN_RASSIGN 635
#define EXPRESSION_SET_ASSIGNED 636
#define EXPRESSION_SET_CHANGED 637
#define EXPRESSION_ASSIGN 638
#define EXPRESSION_DEALLOC 639
#define GEN_ITEM_STRINGIFY 640
#define GEN_ITEM_DISPLAY 641
#define GEN_ITEM_DISPLAY_BLOCK_HELPER 642
#define GEN_ITEM_DISPLAY_BLOCK 643
#define GEN_ITEM_COMPARE 644
#define GEN_ITEM_FIND 645
#define GEN_ITEM_REMOVE_IF_CONTAINS_EXPR_CALLING_STMT 646
#define GEN_ITEM_GET_GENVAR 647
#define GEN_ITEM_VARNAME_CONTAINS_GENVAR 648
#define GEN_ITEM_CALC_SIGNAL_NAME 649
#define GEN_ITEM_CREATE_EXPR 650
#define GEN_ITEM_CREATE_SIG 651
#define GEN_ITEM_CREATE_STMT 652
#define GEN_ITEM_CREATE_INST 653
#define GEN_ITEM_CREATE_TFN 654
#define GEN_ITEM_CREATE_BIND 655
#define GEN_ITEM_RESIZE_STMTS_AND_SIGS 656
#define GEN_ITEM_ASSIGN_EXPR_IDS 657
#define GEN_ITEM_DB_WRITE 658
#define GEN_ITEM_DB_WRITE_EXPR_TREE 659
#define GEN_ITEM_CONNECT 660
#define GEN_ITEM_RESOLVE 661
#define GEN_ITEM_BIND 662
#define GENERATE_RESOLVE 663
#define GENERATE_REMOVE_STMT_HELPER 664
#define GENERATE_REMOVE_STMT 665
#define GEN_ITEM_DEALLOC 666
#define FSM_VAR_ADD 667
#define FSM_VAR_IS_OUTPUT_STATE 668
#define FSM_VAR_BIND_EXPR 669
#define FSM_VAR_ADD_EXPR 670
#define FSM_VAR_BIND_STMT 671
#define FSM_VAR_BIND_ADD 672
#define FSM_VAR_STMT_ADD 673
#define FSM_VAR_BIND 674
#define FSM_VAR_DEALLOC 675
#define FSM_VAR_REMOVE 676
#define FSM_VAR_CLEANUP 677
#define INSTANCE_DISPLAY_TREE_HELPER 678
#define INSTANCE_DISPLAY_TREE 679
#define INSTANCE_CREATE 680
#define INSTANCE_GEN_SCOPE 681
#define INSTANCE_COMPARE 682
#define INSTANCE_FIND_SCOPE 683
#define INSTANCE_FIND_BY_FUNIT 684
#define INSTANCE_ADD_CHILD 685
#define INSTANCE_COPY 686
#define INSTANCE_ATTACH_CHILD 687
#define INSTANCE_PARSE_ADD 688
#define INSTANCE_RESOLVE_INST 689
#define INSTANCE_RESOLVE_HELPER 690
#define INSTANCE_RESOLVE 691
#define INSTANCE_READ_ADD 692
#define INSTANCE_DB_WRITE 693
#define INSTANCE_FLATTEN_HELPER 694
#define INSTANCE_FLATTEN 695
#define INSTANCE_REMOVE_STMT_BLKS_CALLING_STMT 696
#define INSTANCE_REMOVE_PARMS_WITH_EXPR 697
#define INSTANCE_DEALLOC_SINGLE 698
#define INSTANCE_DEALLOC_TREE 699
#define INSTANCE_DEALLOC 700
#define VECTOR_INIT 701
#define VECTOR_CREATE 702
#define VECTOR_COPY 703
#define VECTOR_COPY_RANGE 704
#define VECTOR_CLONE 705
#define VECTOR_DB_WRITE 706
#define VECTOR_DB_READ 707
#define VECTOR_DB_MERGE 708
#define VECTOR_MERGE 709
#define VECTOR_GET_EVAL_A 710
#define VECTOR_GET_EVAL_B 711
#define VECTOR_GET_EVAL_C 712
#define VECTOR_GET_EVAL_D 713
#define VECTOR_GET_EVAL_AB_COUNT 714
#define VECTOR_GET_EVAL_ABC_COUNT 715
#define VECTOR_GET_EVAL_ABCD_COUNT 716
#define VECTOR_GET_TOGGLE01_ULONG 717
#define VECTOR_GET_TOGGLE10_ULONG 718
#define VECTOR_DISPLAY_TOGGLE01_ULONG 719
#define VECTOR_DISPLAY_TOGGLE10_ULONG 720
#define VECTOR_TOGGLE_COUNT 721
#define VECTOR_MEM_RW_COUNT 722
#define VECTOR_SET_ASSIGNED 723
#define VECTOR_SET_COVERAGE_AND_ASSIGN 724
#define VECTOR_GET_SIGN_EXTEND_VECTOR_ULONG 725
#define VECTOR_SIGN_EXTEND_ULONG 726
#define VECTOR_LSHIFT_ULONG 727
#define VECTOR_RSHIFT_ULONG 728
#define VECTOR_SET_VALUE 729
#define VECTOR_PART_SELECT_PULL 730
#define VECTOR_PART_SELECT_PUSH 731
#define VECTOR_SET_UNARY_EVALS 732
#define VECTOR_SET_AND_COMB_EVALS 733
#define VECTOR_SET_OR_COMB_EVALS 734
#define VECTOR_SET_OTHER_COMB_EVALS 735
#define VECTOR_IS_UKNOWN 736
#define VECTOR_IS_NOT_ZERO 737
#define VECTOR_SET_TO_X 738
#define VECTOR_TO_INT 739
#define VECTOR_TO_UINT64 740
#define VECTOR_TO_SIM_TIME 741
#define VECTOR_FROM_INT 742
#define VECTOR_FROM_UINT64 743
#define VECTOR_SET_STATIC 744
#define VECTOR_TO_STRING 745
#define VECTOR_FROM_STRING 746
#define VECTOR_VCD_ASSIGN 747
#define VECTOR_BITWISE_AND_OP 748
#define VECTOR_BITWISE_NAND_OP 749
#define VECTOR_BITWISE_OR_OP 750
#define VECTOR_BITWISE_NOR_OP 751
#define VECTOR_BITWISE_XOR_OP 752
#define VECTOR_BITWISE_NXOR_OP 753
#define VECTOR_OP_LT 754
#define VECTOR_OP_LE 755
#define VECTOR_OP_GT 756
#define VECTOR_OP_GE 757
#define VECTOR_OP_EQ 758
#define VECTOR_CEQ_ULONG 759
#define VECTOR_OP_CEQ 760
#define VECTOR_OP_CXEQ 761
#define VECTOR_OP_CZEQ 762
#define VECTOR_OP_NE 763
#define VECTOR_OP_CNE 764
#define VECTOR_OP_LOR 765
#define VECTOR_OP_LAND 766
#define VECTOR_OP_LSHIFT 767
#define VECTOR_OP_RSHIFT 768
#define VECTOR_OP_ARSHIFT 769
#define VECTOR_OP_ADD 770
#define VECTOR_OP_NEGATE 771
#define VECTOR_OP_SUBTRACT 772
#define VECTOR_OP_MULTIPLY 773
#define VECTOR_OP_DIVIDE 774
#define VECTOR_OP_MODULUS 775
#define VECTOR_OP_INC 776
#define VECTOR_OP_DEC 777
#define VECTOR_UNARY_INV 778
#define VECTOR_UNARY_AND 779
#define VECTOR_UNARY_NAND 780
#define VECTOR_UNARY_OR 781
#define VECTOR_UNARY_NOR 782
#define VECTOR_UNARY_XOR 783
#define VECTOR_UNARY_NXOR 784
#define VECTOR_UNARY_NOT 785
#define VECTOR_OP_EXPAND 786
#define VECTOR_OP_LIST 787
#define VECTOR_DEALLOC_VALUE 788
#define VECTOR_DEALLOC 789
#define SYMTABLE_ADD_SYM_SIG 790
#define SYMTABLE_INIT 791
#define SYMTABLE_CREATE 792
#define SYMTABLE_ADD 793
#define SYMTABLE_SET_VALUE 794
#define SYMTABLE_ASSIGN 795
#define SYMTABLE_DEALLOC 796
#define FUNIT_INIT 797
#define FUNIT_CREATE 798
#define FUNIT_GET_CURR_MODULE 799
#define FUNIT_GET_CURR_MODULE_SAFE 800
#define FUNIT_GET_CURR_FUNCTION 801
#define FUNIT_GET_CURR_TASK 802
#define FUNIT_GET_PORT_COUNT 803
#define FUNIT_FIND_PARAM 804
#define FUNIT_FIND_SIGNAL 805
#define FUNIT_REMOVE_STMT_BLKS_CALLING_STMT 806
#define FUNIT_GEN_TASK_FUNCTION_NAMEDBLOCK_NAME 807
#define FUNIT_SIZE_ELEMENTS 808
#define FUNIT_DB_WRITE 809
#define FUNIT_DB_READ 810
#define FUNIT_DB_MERGE 811
#define FUNIT_MERGE 812
#define FUNIT_FLATTEN_NAME 813
#define FUNIT_FIND_BY_ID 814
#define FUNIT_IS_TOP_MODULE 815
#define FUNIT_IS_UNNAMED 816
#define FUNIT_IS_UNNAMED_CHILD_OF 817
#define FUNIT_IS_CHILD_OF 818
#define FUNIT_DISPLAY_SIGNALS 819
#define FUNIT_DISPLAY_EXPRESSIONS 820
#define STATEMENT_ADD_THREAD 821
#define FUNIT_PUSH_THREADS 822
#define STATEMENT_DELETE_THREAD 823
#define FUNIT_CLEAN 824
#define FUNIT_DEALLOC 825
#define ARC_FIND_FROM_STATE 826
#define ARC_FIND_TO_STATE 827
#define ARC_FIND_ARC 828
#define ARC_CREATE 829
#define ARC_ADD 830
#define ARC_STATE_HITS 831
#define ARC_TRANSITION_HITS 832
#define ARC_TRANSITION_EXCLUDED 833
#define ARC_GET_STATS 834
#define ARC_DB_WRITE 835
#define ARC_DB_READ 836
#define ARC_DB_MERGE 837
#define ARC_MERGE 838
#define ARC_GET_STATES 839
#define ARC_GET_TRANSITIONS 840
#define ARC_ARE_ANY_EXCLUDED 841
#define ARC_DEALLOC 842
#define FUNC_ITER_DISPLAY 843
#define FUNC_ITER_SORT 844
#define FUNC_ITER_COUNT_STMT_ITERS 845
#define FUNC_ITER_ADD_STMT_ITERS 846
#define FUNC_ITER_INIT 847
#define FUNC_ITER_GET_NEXT_STATEMENT 848
#define FUNC_ITER_DEALLOC 849
#define EXCLUDE_EXPR_ASSIGN_AND_RECALC 850
#define EXCLUDE_SIG_ASSIGN_AND_RECALC 851
#define EXCLUDE_ARC_ASSIGN_AND_RECALC 852
#define EXCLUDE_IS_LINE_EXCLUDED 853
#define EXCLUDE_SET_LINE_EXCLUDE 854
#define EXCLUDE_IS_TOGGLE_EXCLUDED 855
#define EXCLUDE_SET_TOGGLE_EXCLUDE 856
#define EXCLUDE_IS_COMB_EXCLUDED 857
#define EXCLUDE_SET_COMB_EXCLUDE 858
#define EXCLUDE_IS_FSM_EXCLUDED 859
#define EXCLUDE_SET_FSM_EXCLUDE 860
#define EXCLUDE_IS_ASSERT_EXCLUDED 861
#define EXCLUDE_SET_ASSERT_EXCLUDE 862
#define RACE_BLK_CREATE 863
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT_HELPER 864
#define RACE_FIND_HEAD_STATEMENT_CONTAINING_STATEMENT 865
#define RACE_GET_HEAD_STATEMENT 866
#define RACE_FIND_HEAD_STATEMENT 867
#define RACE_CALC_STMT_BLK_TYPE 868
#define RACE_CALC_EXPR_ASSIGNMENT 869
#define RACE_CALC_ASSIGNMENTS 870
#define RACE_HANDLE_RACE_CONDITION 871
#define RACE_CHECK_ASSIGNMENT_TYPES 872
#define RACE_CHECK_ONE_BLOCK_ASSIGNMENT 873
#define RACE_CHECK_RACE_COUNT 874
#define RACE_CHECK_MODULES 875
#define RACE_DB_WRITE 876
#define RACE_DB_READ 877
#define RACE_GET_STATS 878
#define RACE_REPORT_SUMMARY 879
#define RACE_REPORT_VERBOSE 880
#define RACE_REPORT 881
#define RACE_COLLECT_LINES 882
#define RACE_BLK_DELETE_LIST 883
#define STATISTIC_CREATE 884
#define STATISTIC_IS_EMPTY 885
#define STATISTIC_DEALLOC 886
#define TCL_FUNC_GET_RACE_REASON_MSGS 887
#define TCL_FUNC_GET_FUNIT_LIST 888
#define TCL_FUNC_GET_INSTANCES 889
#define TCL_FUNC_GET_INSTANCE_LIST 890
#define TCL_FUNC_IS_FUNIT 891
#define TCL_FUNC_GET_FUNIT 892
#define TCL_FUNC_GET_INST 893
#define TCL_FUNC_GET_FUNIT_NAME 894
#define TCL_FUNC_GET_FILENAME 895
#define TCL_FUNC_INST_SCOPE 896
#define TCL_FUNC_GET_FUNIT_START_AND_END 897
#define TCL_FUNC_COLLECT_UNCOVERED_LINES 898
#define TCL_FUNC_COLLECT_COVERED_LINES 899
#define TCL_FUNC_COLLECT_RACE_LINES 900
#define TCL_FUNC_COLLECT_UNCOVERED_TOGGLES 901
#define TCL_FUNC_COLLECT_COVERED_TOGGLES 902
#define TCL_FUNC_COLLECT_UNCOVERED_MEMORIES 903
#define TCL_FUNC_COLLECT_COVERED_MEMORIES 904
#define TCL_FUNC_GET_TOGGLE_COVERAGE 905
#define TCL_FUNC_GET_MEMORY_COVERAGE 906
#define TCL_FUNC_COLLECT_UNCOVERED_COMBS 907
#define TCL_FUNC_COLLECT_COVERED_COMBS 908
#define TCL_FUNC_GET_COMB_EXPRESSION 909
#define TCL_FUNC_GET_COMB_COVERAGE 910
#define TCL_FUNC_COLLECT_UNCOVERED_FSMS 911
#define TCL_FUNC_COLLECT_COVERED_FSMS 912
#define TCL_FUNC_GET_FSM_COVERAGE 913
#define TCL_FUNC_COLLECT_UNCOVERED_ASSERTIONS 914
#define TCL_FUNC_COLLECT_COVERED_ASSERTIONS 915
#define TCL_FUNC_GET_ASSERT_COVERAGE 916
#define TCL_FUNC_OPEN_CDD 917
#define TCL_FUNC_CLOSE_CDD 918
#define TCL_FUNC_SAVE_CDD 919
#define TCL_FUNC_MERGE_CDD 920
#define TCL_FUNC_GET_LINE_SUMMARY 921
#define TCL_FUNC_GET_TOGGLE_SUMMARY 922
#define TCL_FUNC_GET_MEMORY_SUMMARY 923
#define TCL_FUNC_GET_COMB_SUMMARY 924
#define TCL_FUNC_GET_FSM_SUMMARY 925
#define TCL_FUNC_GET_ASSERT_SUMMARY 926
#define TCL_FUNC_PREPROCESS_VERILOG 927
#define TCL_FUNC_GET_SCORE_PATH 928
#define TCL_FUNC_GET_INCLUDE_PATHNAME 929
#define TCL_FUNC_GET_GENERATION 930
#define TCL_FUNC_SET_LINE_EXCLUDE 931
#define TCL_FUNC_SET_TOGGLE_EXCLUDE 932
#define TCL_FUNC_SET_MEMORY_EXCLUDE 933
#define TCL_FUNC_SET_COMB_EXCLUDE 934
#define TCL_FUNC_FSM_EXCLUDE 935
#define TCL_FUNC_SET_ASSERT_EXCLUDE 936
#define TCL_FUNC_GENERATE_REPORT 937
#define TCL_FUNC_INITIALIZE 938
#define STATIC_EXPR_GEN_UNARY 939
#define STATIC_EXPR_GEN 940
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_PRE 941
#define STATIC_EXPR_CALC_LSB_AND_WIDTH_POST 942
#define STATIC_EXPR_DEALLOC 943
#define VCDID 944
#define VCD_CALLBACK 945
#define LXT_PARSE 946
#define COMMAND_MERGE 947
#define LINE_GET_STATS 948
#define LINE_COLLECT 949
#define LINE_GET_FUNIT_SUMMARY 950
#define LINE_GET_INST_SUMMARY 951
#define LINE_DISPLAY_INSTANCE_SUMMARY 952
#define LINE_INSTANCE_SUMMARY 953
#define LINE_DISPLAY_FUNIT_SUMMARY 954
#define LINE_FUNIT_SUMMARY 955
#define LINE_DISPLAY_VERBOSE 956
#define LINE_INSTANCE_VERBOSE 957
#define LINE_FUNIT_VERBOSE 958
#define LINE_REPORT 959

extern profiler profiles[NUM_PROFILES];
#endif

extern unsigned int profile_index;

#endif

