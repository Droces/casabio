<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPMwgRs;

use PHPExiftool\Driver\AbstractTag;

class RegionFocusUsage extends AbstractTag
{

    protected $Id = 'RegionsRegionListFocusUsage';

    protected $Name = 'RegionFocusUsage';

    protected $FullName = 'XMP::mwg_rs';

    protected $GroupName = 'XMP-mwg-rs';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-mwg-rs';

    protected $g2 = 'Image';

    protected $Type = 'string';

    protected $Writable = true;

    protected $Description = 'Region Focus Usage';

    protected $flag_List = true;

    protected $Values = array(
        'EvaluatedNotUsed' => array(
            'Id' => 'EvaluatedNotUsed',
            'Label' => 'Evaluated, Not Used',
        ),
        'EvaluatedUsed' => array(
            'Id' => 'EvaluatedUsed',
            'Label' => 'Evaluated, Used',
        ),
        'NotEvaluatedNotUsed' => array(
            'Id' => 'NotEvaluatedNotUsed',
            'Label' => 'Not Evaluated, Not Used',
        ),
    );

}
