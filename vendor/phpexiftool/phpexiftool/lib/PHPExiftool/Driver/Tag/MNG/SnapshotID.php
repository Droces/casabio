<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\MNG;

use PHPExiftool\Driver\AbstractTag;

class SnapshotID extends AbstractTag
{

    protected $Id = 0;

    protected $Name = 'SnapshotID';

    protected $FullName = 'MNG::ExportImage';

    protected $GroupName = 'MNG';

    protected $g0 = 'MNG';

    protected $g1 = 'MNG';

    protected $g2 = 'Image';

    protected $Type = 'int16u';

    protected $Writable = false;

    protected $Description = 'Snapshot ID';

}
